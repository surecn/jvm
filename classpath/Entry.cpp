//
// Created by 郑邦国 on 2018/10/30.
//

#include "Entry.h"
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;
using namespace classpath;

Entry* Entry::newEntry(string path) {
    if (path.find("/", 0) >= 0) {
        return CompositeEntry::newCompositeEntry(path);
    }
    if (path.find("*", 0) >= 0) {
        return WildcardEntry::newWildcardEntry();
    }
    if (StrUtils::endsWith(path, "*")) {
        return WildcardEntry::newWildcardEntry();
    }
    if (StrUtils::endsWith(path, ".jar") || StrUtils::endsWith(path, ".JAR")
        || StrUtils::endsWith(path, ".zip") || StrUtils::endsWith(path, ".ZIP")) {
        return ZipEntry::newZipEntry(path);
    }
    return new DirEntry(path);
}

int GetFileSizeAndContent(string& fileName, long& size, byte* &data) {
    FILE * pFile;
    pFile = fopen( fileName.c_str(), "rb");
    if (pFile == NULL) {
        return 0;
    }
    else {
        fseek(pFile, 0, SEEK_END);
        size = ftell(pFile);
        if (0 == size) {
            size = 0;
            data = new byte[0];
            fclose(pFile);
            return 1;
        }
        data = new byte[size];
        fseek(pFile, 0, SEEK_SET);
        fread((char*)&data, size, 1, pFile);
        fclose(pFile);
    }
    return 1 ;
}


void DirEntry::readClass(string className, classpath::ClassData &data) {
    string filepath = apply(className);

    long size;
    data.error = !GetFileSizeAndContent(filepath, size, data.data);
}

string DirEntry::toString() {
    return NULL;
}




