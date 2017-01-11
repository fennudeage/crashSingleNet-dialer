#include<WinSock2.h>
#include "dialup.h"
#include"mainwidget.h"

//#include<Windows.h>
//#include<afx.h>
#include<cstring>
#include"md5.h"
#include<time.h>
#include<QCryptographicHash>
#include<QDebug>

//#include<stdlib.h>
#include<QTextStream>
#include<QFile>


using namespace std;
#pragma comment(lib, "ws2_32")
#pragma comment(lib,"RASAPI32.Lib")

  dialup::dialup()
{
    /*wcscpy(musername,user);
    wcscpy(mpasswd,password);
    wcscpy(mentryname,entryName);

      wcscpy(parms.szUserName,user);
      wcscpy(parms.szPassword,password);
      wcscpy(parms.szEntryName,entryName);*/


}
DWORD dialup::connection(){
 //RasDial(NULL,NULL,&parms,NULL,dialup::RAScallback,&handle);

   // memset(&parms,0,sizeof(RASDIALPARAMS));

//ZeroMemory(&parms,sizeof(RASDIALPARAMS));
//WCHAR *phonebook=new wchar_t[256];

//qApp->applicationDirPath().append("\新建文本文档.PBK").toWCharArray(phonebook);

res=RasDialA(NULL,0 ,&parms,0,NULL,&handle);
return res;


}
dialup::~dialup(){

}
 void dialup::dissconnect(){


 DWORD res= RasHangUpA(handle);
  handle=NULL;




}
 dialup::dialup(QString muser, QString mpassword):Radious("singlenet01"),LR("\r\n")
 {

    /* mpassword.toWCharArray(parms.szPassword);

mentry.toWCharArray(parms.szEntryName);*/
      std::string tempsec=portsecret(muser.toStdString());

       qDebug()<<QString(tempsec.c_str()) ;




     strcpy(parms.szEntryName,"滑稽拨号");
    parms.szPhoneNumber[0]='\0';
      parms.szCallbackNumber[0]='\0';
        parms.szDomain[0]='\0';
     strcpy(parms.szUserName,tempsec.c_str());
      // wprintf(stringtoWchar_t(QString(tempsec.c_str())));
       strcpy(parms.szPassword,/*(const wchar_t*)mpassword.toStdString().c_str()*/mpassword.toStdString().c_str());
     handle=NULL;
      parms.dwSize=sizeof(RASDIALPARAMS);


      /* wcscpy(parms.szUserName,L"lllll");
       wcscpy(parms.szPassword,L"lllll");
         wcscpy(parms.szEntryName,L"lllll");
            */

        if(creatRasentry()){
       connection();

                qDebug() <<res;
            if(res!=0){
              this->dissconnect();
            }
        }
        else{
         qDebug()<<"创建失败";
        }
   // handle=NULL;
 }
 bool dialup::creatRasentry(){
   /*   LPRASENTRY lpentry=NULL;
     DWORD dwBufferSize=0;
    RasGetEntryProperties(NULL, L"", NULL, &dwBufferSize, NULL, NULL);
     lpentry = (LPRASENTRY)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwBufferSize);
     ZeroMemory(lpentry, sizeof(RASENTRY));
         lpentry->dwSize		= dwBufferSize;
         lpentry->dwfOptions  = RASEO_RemoteDefaultGateway|RASEO_PreviewPhoneNumber|RASEO_PreviewUserPw;
         lpentry->dwType		= RASET_Internet;

         lstrcpy(lpentry->szDeviceType, RASDT_PPPoE);
         lstrcpy(lpentry->szDeviceName, L"滑稽拨号");
         lpentry->dwfNetProtocols   = RASNP_Ip;
         lpentry->dwFramingProtocol = RASFP_Ppp;


        DWORD entryrtn=     RasSetEntryProperties(NULL, L"滑稽拨号", lpentry, dwBufferSize, NULL, 0);
         HeapFree(GetProcessHeap(), 0, (LPVOID)lpentry);
        if(entryrtn!=0)
        return false;
        return true;
*/
     RASENTRYA pRasEntry;

            // memset(&pRasEntry, 0, sizeof(pRasEntry));
             DWORD pRasEntrySize = 0;

             //获取操作系统中RasEntry的大小
             RasGetEntryPropertiesA(NULL, NULL, NULL, &pRasEntrySize, NULL, NULL);

             pRasEntry.szLocalPhoneNumber[0] = '\0';
             strcpy(pRasEntry.szDeviceType, "RASDT_PPPoE");
             pRasEntry.dwFramingProtocol = RASFP_Ppp;
             pRasEntry.dwType = RASET_Broadband;
             pRasEntry.dwfOptions = RASEO_SwCompression | RASEO_RemoteDefaultGateway | RASEO_NetworkLogon ;
             pRasEntry.dwfNetProtocols = RASNP_Ip | RASNP_Ipv6;
             pRasEntry.dwEncryptionType = ET_Optional;
             pRasEntry.dwfOptions2 = RASEO2_Internet | RASEO2_IPv6RemoteDefaultGateway;
             strcpy(pRasEntry.szDeviceName, "滑稽拨号");
             pRasEntry.dwSize = pRasEntrySize;//sizeof(pRasEntry);
         DWORD retentry=   RasSetEntryPropertiesA(NULL, "滑稽拨号", &pRasEntry, pRasEntrySize, NULL, 0);
          //  if(retentry !=ERROR_SUCCESS){
                return true;
           // }
          //  return false;

 }
   string  dialup::portsecret(string sourceUsername){


     time_t m_time = 0;						//得到系统时间，从1970.01.01.00:00:00 开始的秒数
     long m_time1c = 0;						//时间初处理m_time1c为结果,经过时间计算出的第一次加密
     long temp = 0;
     int i = 0, j = 0, k = 0;
      int lenth = 0;

     unsigned char ss[4] = {0};		//源数据1,对m_time1convert进行计算得到格式符源数据
     unsigned char pad1[4] = {0};

     //格式符初加密
     unsigned char pp[4] = {0};
     unsigned char pf[6] = {0};
     char temp1[100];

  QString  strS1;						//md5加密参数的一部分,ss2的整体形式
     string  strInput;
      string  m_formatsring;				//由m_timece算出的字符串,一般为可视字符
     string  m_md5;						//对初加密(m_timec字符串表示+m_username+radius)的MD5加密
    string  m_md5use;					//md5 Lower模式的前两位


     //取得系统时间m_time
     time(&m_time);
     //时间初处理m_time1c为结果,经过时间计算出的第一次加密
     //子函数////////////////////////////

     m_time1c = (m_time * 0x66666667) >> 0x21;

     //5秒内动态用户名一致处理
     if (m_time1c <= m_lasttimec)
     {
         m_time1c = m_lasttimec + 1;
     }
     m_lasttimec = m_time1c;

     temp = htonl(m_time1c);
     memcpy(pad1, &temp, 4);

     for (int i = 0; i < 4; i++)
     {
         strS1 += pad1[i];
     }

     memcpy(ss, &m_time1c, 4);

     //子函数////////////////////////////

     for (i = 0; i < 32; i++)
     {
         j = i / 8;
         k = 3 - (i % 4);
         pp[k] *= 2;
         if (ss[j] % 2 == 1)
         {
             pp[k]++;
         }
         ss[j] /= 2;
     }


     pf[0] = pp[3] / 0x4;
     pf[1] = (pp[2] / 0x10) | ((pp[3] & 0x3) * 0x10);
     pf[2] = (pp[1] / 0x40) | (pp[2] & 0x0F) * 0x04;
     pf[3] = pp[1] & 0x3F;
     pf[4] = pp[0] / 0x04;
     pf[5] = (pp[0] & 0x03) * 0x10;

     /////////////////////////////////////

     for (i = 0; i < 6; i++)
     {
         pf[i] += 0x20;
         if ((pf[i]) >= 0x40)
         {
             pf[i]++;
         }
     }

     for (i = 0; i < 6; i++)
     {
         m_formatsring += pf[i];
     }

     /////////////////////////////////////
   QString tempsource=QString(QString::fromLocal8Bit(sourceUsername.c_str()));
    QString Qtemp1=  tempsource.left(tempsource.indexOf('@'));
    qDebug()<<tempsource.indexOf('@');

   Qtemp1= Qtemp1+QString(QString::fromLocal8Bit(Radious.c_str()));
    qDebug()<<Qtemp1;
    strS1=strS1+Qtemp1;
     strInput=strS1.toStdString();

    qDebug()<<QString::fromLocal8Bit(strInput.c_str());


     /*QFile file("D:/Qtlianxi/comicaldialing/debugLog.txt");
     file.open(QFile::WriteOnly|QFile::Text);
     QTextStream outputstream(&file);

    // outputstream<<QByteArray(strS1.c_str());
    outputstream<<'1';
    file.flush();
    file.close();
*/











     lenth = /*sourceUsername.FindOneOf("@")*/tempsource.indexOf('@');
     qDebug()<<lenth+'\n';

     //memcpy(temp1, strInput.c_str()/*.GetBuffer(100)*/, 100);
     strcpy(temp1,strInput.c_str());
     qDebug()<<QString(QString::fromLocal8Bit(temp1));
     m_md5 = /*MD5String(temp1,tempsource.indexOf('@')+20);*/QString(QCryptographicHash::hash(QByteArray(tempsource.toStdString().c_str()),QCryptographicHash::Md5)).toStdString();
     qDebug()<<tempsource.indexOf('@')+20;
     qDebug()<<QString(QString::fromLocal8Bit(m_md5.c_str()));
     m_md5use = /*m_md5.Left(2)*/(QString(QString::fromLocal8Bit(m_md5.c_str())).left(2)).toStdString();
     m_realusername = "\r\n" + m_formatsring + m_md5use + /*m_username*/ sourceUsername;
    qDebug()<<'\n';
    qDebug()<<QString(QString::fromLocal8Bit(m_md5.c_str())).left(2);
 // #define _debug
 // #ifdef _debugm_username
 // cout<<"m_username.FindOneOf(\"@\"):"<<m_username.FindOneOf("@")<<"\nm_username.left():"<<m_username.Left(m_username.FindOneOf("@"))<<endl;
 // cout<<"sizeof(int):"<<sizeof(int)<<",m_formatsring:"<<m_formatsring<<endl<<"temp1:"<<temp1<<",m_md5:"<<m_md5<<endl<<"m_realusername:"<<m_realusername<<", m_md5use:"<< m_md5use<<endl;
 // #endif
     return m_realusername;


 }


