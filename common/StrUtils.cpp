//
// Created by 郑邦国 on 2018/11/18.
//

#include "StrUtils.h"

namespace StrUtils {
    void Replace(std::string&srcstr,const std::string&oldstr,const std::string&newstr)
    {
        string::size_type pos=0;
        string::size_type a=oldstr.size();
        string::size_type b=newstr.size();
        while((pos=srcstr.find(oldstr,pos))!=string::npos)
        {
            srcstr.replace(pos,a,newstr);
            pos+=b;
        }
    }

    std::vector<std::string> Split(std::string& str, const char* c)
    {
        char *cstr, *p;
        std::vector<std::string> res;
        cstr = new char[str.size() + 1];
        strcpy(cstr, str.c_str());
        p = strtok(cstr, c);
        while (p != NULL)
        {
            res.push_back(p);
            p = strtok(NULL, c);
        }
        return res;
    }

    std::string TrimLeft(const std::string& str) {
        std::string t = str;
        for (std::string::iterator i = t.begin(); i != t.end(); i++) {
            if (!isspace(*i)) {
                t.erase(t.begin(), i);
                break;
            }
        }
        return t;
    }

    std::string TrimRight(const std::string& str) {
        if (str.begin() == str.end()) {
            return str;
        }
        std::string t = str;
        for (std::string::iterator i = t.end() - 1; i != t.begin(); i--) {
            if (!isspace(*i)) {
                t.erase(i + 1, t.end());
                break;
            }
        }
        return t;
    }

    std::string Trim(const std::string& str) {
        std::string t = str;

        std::string::iterator i;
        for (i = t.begin(); i != t.end(); i++) {
            if (!isspace(*i)) {
                t.erase(t.begin(), i);
                break;
            }
        }
        if (i == t.end()) {
            return t;
        }

        for (i = t.end() - 1; i != t.begin(); i--) {
            if (!isspace(*i)) {
                t.erase(i + 1, t.end());
                break;
            }
        }
        return t;
    }
}
