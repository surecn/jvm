//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_CONSTANTPOOL_H
#define JVM_CONSTANTPOOL_H

#include "../common.h"
#include "ClassReader.h"
#include "ConstantInfo.h"

namespace cls {

    class ConstantPool {
    private:
        ConstantInfo** constantInfos;

    public:
        string* getClassName(u2 index);

        string* getUtf8(u2 index);

        void readConstantPool(ClassReader* classReader);

        ConstantInfo* getConstantInfo(u2 index);


        static ConstantInfo* newConstantInfo(u2 tag, ConstantPool *constantPool) {
//        ConstantInfo* info = new ConstantLongInfo();
//        switch (tag) {
//            case CONSTANT_Integer:
//                return new ConstantIntegerInfo();
//            case CONSTANT_Long:
//                return new ConstantLongInfo();
//            case CONSTANT_FLoat:
//                return NULL;
//            default:
//                break;
//        }
            return NULL;
        }

        static ConstantInfo* readConstantInfo(ClassReader* classReader, ConstantPool* constantPool) {
            u2 tag = classReader->readU2();
            return newConstantInfo(tag, constantPool);
        }

    };


}

#endif //JVM_CONSTANTPOOL_H
