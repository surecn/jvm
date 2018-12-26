//
// Created by 郑邦国 on 2018/12/25.
//

#include "ZipEntry.h"
#include "../common/ZipUtils.h"

namespace cp {

    ZipEntry::ZipEntry(string &path) : m_path(path) {
    }

    void ZipEntry::readClass(string &className, ClassData &data) {
        data.m_error = 0;
        std::vector<string> _vec;
        ZipUtils::getZipList(m_path, &_vec);
        for (int i = 0, len = _vec.size(); i < len; ++i) {
            string s = _vec.at(i);
            if (s == className) {
                string filedata = ZipUtils::readZipFile(m_path, s);
                char *d = new char[filedata.length()];
                memcpy(d, filedata.c_str(), filedata.length());
                data.m_data = (u1*)d;
                data.m_error = 1;
                return;
            }

        }
    }

}