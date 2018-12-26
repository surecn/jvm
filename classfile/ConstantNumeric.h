//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_CONSTANTNUMERIC_H
#define JVM_CONSTANTNUMERIC_H


#include "ClassReader.h"
#include "ConstantInfo.h"

namespace cf {

    class ConstantFloatInfo : public ConstantInfo {
    private:
        float m_value;
    public:
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };

    class ConstantDoubleInfo : public ConstantInfo {
    private:
        double m_value;
    public:
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };

    class ConstantIntegerInfo : public ConstantInfo {
    private:
        int m_value;
    public:
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };

    class ConstantLongInfo : public ConstantInfo {
    private:
        long m_value;
    public:
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };

}


#endif //JVM_CONSTANTNUMERIC_H
