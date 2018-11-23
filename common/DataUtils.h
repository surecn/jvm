//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_DATAUTILS_H
#define JVM_DATAUTILS_H


namespace DataUtils {

    inline static void floatToBytes(float val, unsigned char *bytes) {
        unsigned char charArray[4];
        unsigned char *pdata = (unsigned char *)&val;  //把float类型的指针强制转换为unsigned char型
        for(int i = 0; i < 4; i++) {
            charArray[i] = *pdata++;//把相应地址中的数据保存到unsigned char数组中
        }
        bytes = charArray;
    }

    inline static void doubleToBytes(double val, unsigned char *bytes) {
        unsigned char charArray[8];
        unsigned char *pdata = (unsigned char *)&val;  //把float类型的指针强制转换为unsigned char型
        for(int i = 0; i < 8; i++) {
            charArray[i] = *pdata++;//把相应地址中的数据保存到unsigned char数组中
        }
        bytes = charArray;
    }

    inline static int bytesToInt(unsigned char data[], int length) {//小端法
        int val = 0;
        for (int i = 0; i < length; ++i) {
            val |= (data[i] << (i * 8));
        }
    }

};


#endif //JVM_DATAUTILS_H
