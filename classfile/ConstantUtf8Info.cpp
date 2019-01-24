//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantUtf8Info.h"

namespace cf {

    void ConstantUtf8Info::readInfo(cf::ClassReader *classReader) {
        m_length = classReader->readU2();
        m_bytes = classReader->readU1s(m_length);
        decodeMUTF8(m_bytes, m_length);
    }

    void ConstantUtf8Info::decodeMUTF8(u1 *bytearr, int utflen) {
        char16_t chararr[utflen];
        for (int i = 0; i < utflen; i ++) chararr[i] = 0;
        char16_t c, char2, char3;
        int count = 0;
        int chararr_count = 0;
        while (count < utflen) {
            c = (char16_t)(bytearr[count] & 0xff);
            if (c > 127) {
                break;
            }
            count++;
            chararr[chararr_count] = c;
            chararr_count++;
        }
        while (count < utflen) {
            c = (char16_t) (bytearr[count] & 0xff);
            switch (c >> 4) {
                case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
                    /* 0xxxxxxx*/
                    count++;
                    chararr[chararr_count++]=(char16_t)c;
                    break;
                case 12: case 13:
                    /* 110x xxxx   10xx xxxx*/
                    count += 2;
                    if (count > utflen)
                        logError("malformed input: partial character at end");
                    char2 = (char16_t) bytearr[count-1];
                    if ((char2 & 0xC0) != 0x80)
                        logError("malformed input around byte " + count);
                    chararr[chararr_count++]=(char16_t)(((c & 0x1F) << 6) |
                                                    (char2 & 0x3F));
                    break;
                case 14:
                    /* 1110 xxxx  10xx xxxx  10xx xxxx */
                    count += 3;
                    if (count > utflen)
                        logError("malformed input: partial character at end");
                    char2 = (char16_t) bytearr[count-2];
                    char3 = (char16_t) bytearr[count-1];
                    if (((char2 & 0xC0) != 0x80) || ((char3 & 0xC0) != 0x80))
                        logError("malformed input around byte " + (count-1));
                    chararr[chararr_count++]=(char16_t)(((c     & 0x0F) << 12) |
                                                    ((char2 & 0x3F) << 6)  |
                                                    ((char3 & 0x3F) << 0));
                    break;
                default:
                    /* 10xx xxxx,  1111 xxxx */
                    logError("malformed input around byte " + count);
            }
        }
        char16_t newarr[chararr_count + 1];
        for (int i = 0; i < chararr_count; i++) {
            newarr[i] = (char16_t)chararr[i];
        }
        newarr[chararr_count] = '\0';
        m_str = StrUtils::wstringToString(newarr);
    }

    string* ConstantUtf8Info::value() {
        return &m_str;
    }

    void* ConstantUtf8Info::getValue() {
        return &m_str;
    }

    void ConstantUtf8Info::print() {
        cout << "UTF8:" << m_str << endl;
    }

}