#include "tool.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
Tool::Tool()
{


}
 long GetTimestampMills()
       {
           TimeSpan ts = DateTime.UtcNow - new DateTime(1970, 1, 1, 0, 0, 0, 0);
           return Convert.ToInt64(ts.TotalMilliseconds);
       }
 long GetTimestamp()
         {
             TimeSpan ts = DateTime.UtcNow - new DateTime(1970, 1, 1, 0, 0, 0, 0);
             return Convert.ToInt64(ts.TotalMilliseconds) / 1000;
         }
  string Bytes2string(unsigned char* b)
        {
            return System.Text.Encoding.Default.GetString(b);
        }
  unsigned char * String2bytes(string str)
         {
             return System.Text.Encoding.Default.GetBytes(str);
         }
  unsigned char * Encode( unsigned char *str)
             {
                 //System.Security.Cryptography.MD5 md5 = System.Security.Cryptography.MD5.Create();
                unsigned char * data = md5.ComputeHash(str);
                 string am = "";
                 for (int h = 0; h < data.Length; h++)
                 {
                     am = am + data[h].ToString("x2");
                 }
                unsigned char *data32 = new unsigned char [32];
                 data32 = String2bytes(am);
                 md5.Clear();
                 return data32;
             }
  string Encode2string( unsigned char * str)
              {
                  return Bytes2string(Encode(str));
              }
 unsigned char * Encode(string str)
              {
                  return Encode(String2bytes(str));
              }
 string Encode2string(string str)
             {
                 return Bytes2string(Encode(str));
             }
