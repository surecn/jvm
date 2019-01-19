//
// Created by 郑邦国 on 2019/1/7.
//

#include <codecvt>
#include "StringPool.h"

namespace rt {

    map<string, Object*> StringPool::m_internedStrings;

    Object* StringPool::getJString(rt::ClassLoader *loader, string str) {
        Object *value = m_internedStrings[str];
        if (value != NULL) {
            return m_internedStrings[str];
        }

        u16string *str_u16 = new u16string(stringToWString(str));
        const char16_t* chars = str_u16->data();
        string clsCArrayName("[C");
        Object *obj = new Object(loader->loadClass(&clsCArrayName), (void*)chars, str.length());
        string clsStringName("java/lang/String");
        Class *clsString = loader->loadClass(&clsStringName);
        Object *objStr = new Object(clsString);
        string fieldName("value");
        objStr->setRefVar(&fieldName, &clsCArrayName, obj);
        m_internedStrings[str] = objStr;

        cout << "getJString:" << str << "  " << objStr << obj << chars << endl;
        return objStr;
    }

    string StringPool::getCString(rt::Object *jstr) {
        string name("value");
        string descriptor("[C");
        Object *charArray = jstr->getRefVar(&name, &descriptor);
        const char16_t* chars  = (const char16_t*)charArray->getRefs();
        u16string str(chars);
        return wstringToString(str);
    }

    u16string StringPool::stringToWString(string s) {
        std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t > converter;
        return converter.from_bytes(s);
    }

    string StringPool::wstringToString(u16string s) {
        std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
        return converter.to_bytes(s);
    }

}