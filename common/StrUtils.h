//
// Created by 郑邦国 on 2018/11/14.
//

#ifndef JVM_STRINGUTILS_H
#define JVM_STRINGUTILS_H


#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

namespace StrUtils
{
    static const std::string tag = "[StrUtils] ";

    inline static void replace(std::string&srcstr,const std::string&oldstr,const std::string&newstr)
    {
        std::string::size_type pos=0;
        std::string::size_type a=oldstr.size();
        std::string::size_type b=newstr.size();
        while((pos=srcstr.find(oldstr,pos))!=std::string::npos)
        {
            srcstr.replace(pos,a,newstr);
            pos+=b;
        }
    }

    inline static std::string trimLeft(const std::string& str, const std::string& token = " ")
    {
        std::string t = str;
        t.erase(0, t.find_first_not_of(token));
        return t;
    }

    static std::string trimRight(const std::string& str, const std::string& token = " ")
    {
        std::string t = str;
        t.erase(t.find_last_not_of(token) + 1);
        return t;
    }

    static std::string trim(const std::string& str, const std::string& token = " ")
    {
        std::string t = str;
        t.erase(0, t.find_first_not_of(token));
        t.erase(t.find_last_not_of(token) + 1);
        return t;
    }

    static std::string toLower(const std::string& str)
    {
        std::string t = str;
        std::transform(t.begin(), t.end(), t.begin(), tolower);
        return t;
    }

    static std::string toUpper(const std::string& str)
    {
        std::string t = str;
        std::transform(t.begin(), t.end(), t.begin(), toupper);
        return t;
    }

    static bool startsWith(const std::string& str, const std::string& substr)
    {
        if (str.length() < substr.length()) {
            return false;
        }
        return str.find(substr) == 0;
    }

    static bool endsWith(const std::string& str, const std::string& substr)
    {
        if (str.length() < substr.length()) {
            return false;
        }
        return str.rfind(substr) == (str.length() - substr.length());
    }

    static bool equalsIgnoreCase(const std::string& str1, const std::string& str2)
    {
        return toLower(str1) == toLower(str2);
    }

    static std::vector<std::string> split(const std::string& str, const std::string& delimiter)
    {
        char* save = nullptr;
        char* token = strtok_r(const_cast<char*>(str.c_str()), delimiter.c_str(), &save);
        std::vector<std::string> result;
        while (token != nullptr)
        {
            result.emplace_back(token);
            token = strtok_r(nullptr, delimiter.c_str(), &save);
        }
        return result;
    }


};


#endif //JVM_STRINGUTILS_H
