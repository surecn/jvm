//
// Created by 郑邦国 on 2018/12/25.
//

#include "CompositeEntry.h"
#include "../common/StrUtils.h"


namespace cp {

    void CompositeEntry::addEntry(cp::Entry *entry) {
        m_entryList.push_back(entry);
    }

    CompositeEntry::CompositeEntry() {}

    CompositeEntry::CompositeEntry(string &path) {
        std::vector<string> list = StrUtils::split(path, PATH_SEPARATOR);
        for (int i = 0, len = list.size(); i < len; ++i) {
            string item = list[i];
            m_entryList.push_back(Entry::create(item));
        }
    }

    CompositeEntry::~CompositeEntry() {
        list<Entry *>::iterator iter;
        for(iter = m_entryList.begin(); iter != m_entryList.end(); iter++) {
            Entry *entry = (*iter);
            if (entry) {
                delete entry;
            }
        }
    }

    void CompositeEntry::readClass(string &path, ClassData &data) {
        list<Entry *>::iterator theIterator;
        for (theIterator = m_entryList.begin(); theIterator != m_entryList.end(); theIterator++) {
            Entry *entry = (*theIterator);
            entry->readClass(path, data);
            if (data.m_error == 1) {
                return;
            }
        }
    }


}