//
// Created by 郑邦国 on 2018/12/30.
//

#include "MethodDescriptor.h"

namespace rt {

    void MethodDescriptorParser::reset() {
        m_offset = 0;
        m_raw = NULL;
    }

    MethodDescriptorParser::MethodDescriptorParser() {
        reset();
    }

    void MethodDescriptorParser::startParams() {
        if (readU1() != '(') {
            causePanic();
        }
    }

    void MethodDescriptorParser::endParams() {
        if (readU1() != ')') {
            causePanic();
        }
    }

    void MethodDescriptorParser::finish() {
        if (m_offset != (*m_raw).length()) {
            causePanic();
        }
    }

    void MethodDescriptorParser::causePanic() {
        //string s("BAD descriptor: ");
        //s.append(*m_raw);
        //logError(s);
    }

    u1 MethodDescriptorParser::readU1() {
        u1 ch = (*m_raw)[m_offset];
        m_offset++;
        return ch;
    }

    void MethodDescriptorParser::unreadU1() {
        m_offset--;
    }

    void MethodDescriptorParser::parseReturnType() {
        if (readU1() == 'V') {
            m_parsed->setReturnType('V');
        }
        unreadU1();
        char ch = parseFieldType();
        if (ch != -1) {
            m_parsed->setReturnType(ch);
            return;
        }
        causePanic();
    }

    void MethodDescriptorParser::parseParamTypes() {
        while (true) {
            char ch = parseFieldType();
            if (ch != -1) {
                m_parsed->addParameterType(ch);
            } else {
                break;
            }
        }
    }

    char MethodDescriptorParser::parseFieldType() {
        switch ((char)readU1()) {
            case 'B':
                return 'B';
            case 'C':
                return 'C';
            case 'D':
                return 'D';
            case 'F':
                return 'F';
            case 'I':
                return 'I';
            case 'J':
                return 'J';
            case 'S':
                return 'S';
            case 'Z':
                return 'Z';
            case 'L':
                return parseObjectType();
            case '[':
                return parseArrayType();
            default:
                unreadU1();
                return -1;
        }
    }

    char MethodDescriptorParser::parseObjectType() {
        string unread = m_raw->substr(m_offset, m_raw->length());
        int semicolonIndex = unread.find(';', 0);
        if (semicolonIndex == -1) {
            causePanic();
            return -1;
        } else {
            int objStart = m_offset - 1;
            int objEnd = m_offset + semicolonIndex + 1;
            m_offset = objEnd;
            char descriptor = (*m_raw)[objStart];
            return descriptor;
        }
    }

    char MethodDescriptorParser::parseArrayType() {
        int arrStart = m_offset - 1;
        parseFieldType();
        int arrEnd = m_offset;
        return (*m_raw)[arrStart];
    }

    MethodDescriptor* MethodDescriptorParser::parseMethodDescriptor(string *descriptor) {
        m_raw = descriptor;
        m_parsed = new MethodDescriptor();
        startParams();
        parseParamTypes();
        endParams();
        parseReturnType();
        finish();
        return m_parsed;
    }

    void MethodDescriptor::addParameterType(char t) {
        m_paramaterType.push_back(t);
    }

    char MethodDescriptor::getReturnType() const {
        return m_returnType;
    }

    void MethodDescriptor::setReturnType(char m_returnType) {
        MethodDescriptor::m_returnType = m_returnType;
    }

    const vector<char> &MethodDescriptor::getParamaterType() const {
        return m_paramaterType;
    }


}