//
// Created by 郑邦国 on 2018/12/25.
//

#include "WildcardEntry.h"
#include "ZipEntry.h"
#include <dirent.h>

namespace cp {

    WildcardEntry::WildcardEntry(string &path) {
        m_path = path.substr(0, path.length() - 1);

        DIR *dir;
        struct dirent *ptr;
        if ((dir = opendir(m_path.c_str())) == NULL) {
            cout << "Open dir error" << path << endl;
            return;
        }
        while((ptr = readdir(dir)) != NULL) {
            if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
                continue;
            else if (ptr->d_type == 8) { //file
                string s(ptr->d_name);
                if (StrUtils::endsWith(s, ".jar") || StrUtils::endsWith(s, ".JAR")) {
                    string fullPath = m_path + PATH_SEPARATOR + s;
                    ZipEntry *zipEntry = new ZipEntry(fullPath);
                    addEntry(zipEntry);
                }
            } else if (ptr->d_type == 4) { //dir
//                string s(ptr->d_name);
//                if (m_path != s) {
//                    return;
//                }
            }
        }

    }

}