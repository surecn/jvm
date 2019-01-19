//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_CONSTANTPOOL_H
#define JVM_CONSTANTPOOL_H

#include "../common.h"
#include "ClassReader.h"
#include "ConstantInfo.h"

namespace cf {

    class ConstantPool {
    private:
<<<<<<< HEAD
<<<<<<< HEAD
        ConstantInfo **constantInfos;

        u2 constantPoolSize;

    public:

        ConstantPool(ClassReader *classReader);

        string* getClassName(u2 index);

        string* getUtf8(u2 index);

        ConstantInfo* getConstantInfo(u2 index);

=======
        ConstantInfo **m_listConstant;
        u2 m_constantPoolSize;
    public:
        ConstantPool(ClassReader *classReader);
        string *getClassName(u2 index);
        string *getUtf8(u2 index);
        ConstantInfo* getConstantInfo(u2 index);
        u2 getConstantSize();
        NameAndType getNameAndType(u2 index);
        void print();
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
=======
        ConstantInfo **m_listConstant;
        u2 m_constantPoolSize;
    public:
        ConstantPool(ClassReader *classReader);
        ~ConstantPool();
        string *getClassName(u2 index);
        string *getUtf8(u2 index);
        ConstantInfo* getConstantInfo(u2 index);
        u2 getConstantSize();
        NameAndType getNameAndType(u2 index);
        void print();
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
    };


}

#endif //JVM_CONSTANTPOOL_H
