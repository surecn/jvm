//
// Created by 郑邦国 on 2018/10/30.
//

#include "Entry.h"

Entry* Entry::newEntry(string path) {
    DirEntry dirEntry(path);
    return &dirEntry;
}

void Entry::newCompositeEntry(string path, Entry *compositeEntry) {

}

void DirEntry::readClass(string cls) {

}

string DirEntry::toString() {

}



