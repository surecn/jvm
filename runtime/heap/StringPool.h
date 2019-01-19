//
// Created by 郑邦国 on 2019/1/7.
//

#ifndef JVM_STRINGPOOL_H
#define JVM_STRINGPOOL_H

#include "../../common.h"
#include "ClassLoader.h"
#include <map>
typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t> > u16string;


namespace rt {

    class StringPool {
    private:

    public:
        static map<string, Object*> m_internedStrings;
        static u16string stringToWString(string s);
        static string wstringToString(u16string s);
        static Object* getJString(ClassLoader *loader, string str);
        static string getCString(Object *jstr);

    };

}


#endif //JVM_STRINGPOOL_H
