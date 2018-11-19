//
// Created by 郑邦国 on 2018/11/14.
//

#ifndef JVM_STRINGUTILS_H
#define JVM_STRINGUTILS_H


#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace StrUtils
{
    static const string tag = "[StrUtils] ";
    std::string TrimLeft(const std::string& str);
    std::string TrimRight(const std::string& str);
    std::string Trim(const std::string& str);
    std::vector<std::string> Split(std::string& str, const char* c);
    void Replace(std::string&srcstr,const std::string&oldstr,const std::string&newstr);
};


#endif //JVM_STRINGUTILS_H
