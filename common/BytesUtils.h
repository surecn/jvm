//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_DATAUTILS_H
#define JVM_DATAUTILS_H

#define SIZE_INT sizeof(long)  //win64除外


namespace BytesUtils {

    const unsigned int MATCHARRAY[] = {0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000};

    inline static void floatToBytes(float val, unsigned char *bytes) {
        unsigned char *pdata = (unsigned char *)&val;  //把float类型的指针强制转换为unsigned char型
        for(int i = 0; i < SIZE_INT * 2; i++) {
            bytes[i] = *pdata++;//把相应地址中的数据保存到unsigned char数组中
        }
    }

    inline static float bytesToFloat(unsigned char *bytes) {
        float *val = (float*)bytes;
        return *val;
    }

    inline static void doubleToBytes(double val, unsigned char bytes[]) {
        unsigned char *pdata = (unsigned char *)&val;  //把float类型的指针强制转换为unsigned char型
        for(int i = 0; i < SIZE_INT * 2; i++) {
            bytes[i] = *pdata++;//把相应地址中的数据保存到unsigned char数组中
        }
    }

    inline static double bytesToDouble(unsigned char bytes[]) {
        return *(double*)bytes;
    }


    inline static long bytesToInt(unsigned char *data) {//小端法
        long val = 0;
        for (int i = 0; i < SIZE_INT; ++i) {
            val |= (data[i] << (i * 8));
        }
        return val;
    }

    inline static void intToBytes(long value, unsigned char data[]) {//小端法
        for (int i = 0; i < SIZE_INT; ++i) {
            data[i] = value & MATCHARRAY[i];
        }
    }

};


#endif //JVM_DATAUTILS_H
