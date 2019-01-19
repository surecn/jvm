//
// Created by 郑邦国 on 2018/10/30.
//

#include "Entry.h"
#include <unistd.h>
#include <sys/stat.h>
#include "../common/ZipUtils.h"
#include <unistd.h>
#include "DirEntry.h"
#include "CompositeEntry.h"
#include "WildcardEntry.h"
#include "ZipEntry.h"

namespace cp {

    ClassData::~ClassData() {
        delete m_data;
    }

    Entry *Entry::create(string &path) {
        if (path.find_first_of(PATH_SEPARATOR, 0) != string::npos) {
            return new CompositeEntry(path);
        }
        if (path.find_first_of("*", 0) != string::npos) {
            return new WildcardEntry(path);
        }
        if (StrUtils::endsWith(path, "*")) {
            return new WildcardEntry(path);
        }
        if (StrUtils::endsWith(path, ".jar") || StrUtils::endsWith(path, ".JAR")
            || StrUtils::endsWith(path, ".zip") || StrUtils::endsWith(path, ".ZIP")) {
            return new ZipEntry(path);
        }
        return new DirEntry(path);
    }


}

