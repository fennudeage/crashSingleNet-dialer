#ifndef DIALUP_H
#define DIALUP_H


#include<Windows.h>
#include<tchar.h>
#include<QString>
//#include<WinSock2.h>
//#include<stdafx.h>
#include<string.h>
#include<QDebug>
//#include"md5.h"
#include<Ras.h>
#include<RasError.h>

#include<cstring>

//#include<afxstr.h>

//#pragma comment(lib, "ws2_32")
#pragma comment(lib,"rasapi32.lib")


class dialup
{
public:
   /* static const char * Wchar_tToString( wchar_t *wchar)
    {
    wchar_t * wText = wchar;
    DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wText,-1,NULL,0,NULL,FALSE);// WideCharToMultiByte的运用
    char *psText;  // psText为char*的临时数组，作为赋值给std::string的中间变量
    psText = new char[dwNum];
    WideCharToMultiByte (CP_OEMCP,NULL,wText,-1,psText,dwNum,NULL,FALSE);// WideCharToMultiByte的再次运用
    //szDst = psText;// std::string赋值
     return psText;
    delete []psText;// psText的清除

    }
  static wchar_t  * stringtoWchar_t(std::string tempstring){
      wchar_t*tc;//new wchar_t[tempstring.size()];
      memset(tc,0,tempstring.size());
     wchar_t   *   wc   =   new   wchar_t[tempstring.size()];
     swprintf(wc,L"%S ",tempstring.c_str());//注意大写S。。

     wcscpy(tc,wc);
    // std::wcout <<"szSrc: " << tc <<std::endl;
     return wc;
    }
  static wchar_t  * stringtoWchar_t2(std::string tempstring1){
    const char* source=tempstring1.c_str();
    size_t ssize=tempstring1.size()+1;
    wchar_t *destans= new wchar_t[ssize];
    wmemset(destans,0,ssize);
    return destans;
    delete[] destans;
}

*/





   wchar_t musername[256],mpasswd[256],mentryname[256];
    dialup(QString muser, QString mpassword);
    dialup();
    ~dialup();
    DWORD connection();
      RASDIALPARAMSA parms;
        HRASCONN handle;

     /* static void stringtoTchar(std::string temp){
         TCHAR *ttemp=new TCHAR[sizeof(temp)];

      }
     /* static TCHAR* stringtoTchar(QString temp){
      const char* temp1=temp.toStdString().c_str();
          int size=strlen(temp1);
          TCHAR *string=new TCHAR[sizeof(temp1)];
          mbstowcs(string,temp1,size+1);
        return string;

      }*/
 DWORD res;
private:

    std::string Radious;
   //wchar_t ppp[9];
   std::string m_username;
   std::string m_realusername;
std::string LR;
   long m_lasttimec;
  void dissconnect();
  void  getcurrentconnect();
  bool creatRasentry();
std::string portsecret(std::string sourceUsername);


// static  void WINAPI RAScallback(UINT unMsg,RASCONNSTATE connectstate,DWORD BackErro);


};

#endif // DIALUP_H

