//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_COM_H
#define JVM_COM_H


#include "Entry.h"
#include "../common.h"

namespace cp {

    class CompositeEntry : public Entry {
    private:
        list<Entry*> m_entryList;/*析构函数释放*/
    protected:
        void addEntry(Entry *entry);
    public:
        CompositeEntry();
        CompositeEntry(string &path);
        ~CompositeEntry();
        virtual void readClass(string &path, ClassData &data);
    };

}


#endif //JVM_COM_H
