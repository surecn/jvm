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

<<<<<<< HEAD
namespace classpath {

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
//
//    void Entry::readClass(string path, classpath::ClassData &data) {
//    }


    void DirEntry::readClass(string &className, classpath::ClassData &data) {
        //string filepath = apply(className);

        long size;
        data.error = !GetFileSizeAndContent(className, size, &data.data);
    }

    string DirEntry::toString() {
        return NULL;
    }

    CompositeEntry::CompositeEntry(string &path) {
        std::vector<string> list = StrUtils::split(path, PATH_SEPARATOR);
        for (int i = 0, len = list.size(); i < len; ++i) {
            string item = list[i];
            entryList.push_back(Entry::create(item));
        }
    }

    void CompositeEntry::readClass(string &path, classpath::ClassData &data) {
        list<Entry *>::iterator theIterator;
        for (theIterator = entryList.begin(); theIterator != entryList.end(); theIterator++) {
            Entry *entry = (*theIterator);
            entry->readClass(path, data);
        }
    }

    static string toPathList(string &wildcardPath) {
        StrUtils::replace(wildcardPath, "*", "");
    //    try {
    //        return Files.walk(Paths.get(baseDir))
    //                .filter(Files::isRegularFile)
    //                .map(Path::toString)
    //                .filter(p -> p.endsWith(".jar") || p.endsWith(".JAR"))
    //                .collect(Collectors.joining(File.pathSeparator));
    //    } catch (IOException e) {
    //        //e.printStackTrace(System.err);
    //        return "";
    //    }
        string res = wildcardPath;
        return res;
    }


    WildcardEntry::WildcardEntry(string &path) : parentPath(toPathList(path)), CompositeEntry(parentPath) {
    }

    void ZipEntry::readClass(string &path, classpath::ClassData &data) {
//        try (FileSystem zipFs = FileSystems.newFileSystem(absPath, null)) {
//            return Files.readAllBytes(zipFs.getPath(className));
//        }
    }

}

=======
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

>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
