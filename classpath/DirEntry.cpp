//
// Created by 郑邦国 on 2018/12/25.
//

#include "DirEntry.h"
#include <fstream>

namespace cp {

    static int GetFileSizeAndContent(string& fileName, long& size, byte** data) {
        filebuf *pbuf;
        ifstream filestr;
        filestr.open(fileName, ios::binary);
        pbuf = filestr.rdbuf();
        size = pbuf->pubseekoff(0, ios::end, ios::in);
        pbuf->pubseekpos(0, ios::in);

        *data = (byte*)malloc(sizeof(byte)* size);
        pbuf->sgetn((char*)*data, size);
        filestr.close();
        return 1 ;
    }

    DirEntry::DirEntry(string &s) : m_path(s)
    {}

    void DirEntry::readClass(string &className, ClassData &data) {
        //string filepath = apply(className);

        long size;
        data.m_error = !GetFileSizeAndContent(className, size, &data.m_data);
    }

    string DirEntry::toString() {
        return NULL;
    }

    string DirEntry::apply(string &fileName) {
        return m_path + PATH_SEPARATOR + fileName;
    }



}