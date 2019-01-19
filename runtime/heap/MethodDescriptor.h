//
// Created by 郑邦国 on 2018/12/30.
//

#ifndef JVM_METHODDESCRIPTOR_H
#define JVM_METHODDESCRIPTOR_H

#include "../../common.h"

namespace rt {

    class MethodDescriptor;

    class MethodDescriptorParser {
    private:
        string *m_raw;
        int m_offset;
        MethodDescriptor *m_parsed;
        void startParams();
        void endParams();
        void finish();
        void causePanic();
        u1 readU1();
        void unreadU1();
        void parseReturnType();
        void parseParamTypes();
        char parseFieldType();
        char parseObjectType();
        char parseArrayType();
    public:
        MethodDescriptorParser();
        MethodDescriptor* parseMethodDescriptor(string *descriptor);
        void reset();
    };

    class MethodDescriptor {
    private:
        vector<char> m_paramaterType;
        char m_returnType;
    public:
        void addParameterType(char t);
        char getReturnType() const;
        void setReturnType(char m_returnType);

        const vector<char> &getParamaterType() const;
    };

}


#endif //JVM_METHODDESCRIPTOR_H
