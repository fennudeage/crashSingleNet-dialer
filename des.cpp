#include "des.h"
using namespace std;
Des::Des()
{

}
 string Decrypt(string encryptedString,long timestamp)
      {
          byte btKey[] = getSecKey(timestamp);
          byte btIV[] = getIvKey(timestamp);
          DESCryptoServiceProvider des = new DESCryptoServiceProvider();
        //  using (MemoryStream ms = new MemoryStream())

              byte inData[] = Convert.FromBase64String(encryptedString);

                  //using (CryptoStream cs = new CryptoStream(ms, des.CreateDecryptor(btKey, btIV), CryptoStreamMode.Write))

                      cs.Write(inData, 0, inData.Length);
                      cs.FlushFinalBlock();


                  return Encoding.UTF8.GetString(ms.ToArray());

              catch

                  return null;

              }

  byte* getIvKey(long timestamp)
        {
            byte bytes[] = new byte[8];
            int tmp = (int)((timestamp / 1000 % 100) * (timestamp % 100)) % 100;
            for (int i = 0; i < 8; i++)
            {
                bytes[i] = AES_KEY[tmp];
                tmp = bytes[i];
            }
            return bytes;
        }
 byte* getSecKey(long timestamp)
        {
            return getIvKey(timestamp * 2);
        }

