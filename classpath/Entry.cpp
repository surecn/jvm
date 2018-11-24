//
// Created by 郑邦国 on 2018/10/30.
//

#include "Entry.h"
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

namespace cpath {

    ClassData::~ClassData() {
        delete data;
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

    DirEntry::DirEntry(string &s) : path(s)
    {}

    void DirEntry::readClass(string &className, ClassData &data) {
        //string filepath = apply(className);

        long size;
        data.error = !GetFileSizeAndContent(className, size, &data.data);
    }

    string DirEntry::toString() {
        return NULL;
    }

    string DirEntry::apply(string &fileName) {
        return path + PATH_SEPARATOR + fileName;
    }

    CompositeEntry::CompositeEntry(string &path) {
        std::vector<string> list = StrUtils::split(path, PATH_SEPARATOR);
        for (int i = 0, len = list.size(); i < len; ++i) {
            string item = list[i];
            entryList.push_back(Entry::create(item));
        }
    }

    CompositeEntry::~CompositeEntry() {
        list<Entry *>::iterator iter;
        for(iter = entryList.begin(); iter != entryList.end(); iter++) {
            Entry *entry = (*iter);
            if (entry) {
                delete entry;
            }
        }
    }

    void CompositeEntry::readClass(string &path, ClassData &data) {
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

    void ZipEntry::readClass(string &path, ClassData &data) {
//        try (FileSystem zipFs = FileSystems.newFileSystem(absPath, null)) {
//            return Files.readAllBytes(zipFs.getPath(className));
//        }
    }

}

