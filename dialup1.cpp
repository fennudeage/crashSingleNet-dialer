#include "dialup1.h"

dialup1::dialup1(QObject *parent) : QObject(parent)
{

}
void dialup1::dialup(wchar_t user[], wchar_t password[], wchar_t entryName[]){
    wcscpy(musername,user);
    wcscpy(mpasswd,password);
    wcscpy(mentryname,entryName);
parms.dwSize=sizeof(RASDIALPARAMS);
}
void dialup::connection(){
 //RasDial(NULL,NULL,&parms,NULL,dialup::RAScallback,&handle);

wcscpy(parms.szUserName,musername);
wcscpy(parms.szPassword,mpasswd);
wcscpy(parms.szEntryName,mentryname);
DWORD rrr=RasDial(NULL,NULL,&parms,0,NULL,&handle);


}
void dialup::dissconnect(){
DWORD res= RasHangUp(handle);
 handle=NULL;




}


