//
// Created by 郑邦国 on 2018/12/24.
//

#ifndef JVM_ZIPUTILS_H
#define JVM_ZIPUTILS_H

#include <zlib.h>
#include "../libs/unzip.h"
#include "../common.h"

class ZipUtils {
public:
    static string readZipFile(string zipFile, string fileInZip);
    static void getZipList(string zipFile, std::vector<string> *_vector);
};


#endif //JVM_ZIPUTILS_H
