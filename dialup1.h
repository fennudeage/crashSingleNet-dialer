#ifndef DIALUP1_H
#define DIALUP1_H
#pragma(lib,"Rasapi32.lib")
#include <QObject>

#include<Windows.h>

#include<tchar.h>
#include<QString>
#include<Ras.h>
#include<RasError.h>
class dialup1 : public QObject
{
    Q_OBJECT
public:
    explicit dialup1(QObject *parent = 0);
    void dialup(wchar_t user[], wchar_t password[], wchar_t entryName[]);
     void connection();
       RASDIALPARAMS parms;
 private:
     DWORD res;
    wchar_t musername[30],mpasswd[30],mentryname[30];
    //wchar_t ppp[9];
   void dissconnect();
   void  getcurrentconnect();
 // static  void WINAPI RAScallback(UINT unMsg,RASCONNSTATE connectstate,DWORD BackErro);

     HRASCONN handle;
signals:

public slots:
};

#endif // DIALUP1_H
