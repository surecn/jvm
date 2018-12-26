//
// Created by 郑邦国 on 2018/12/25.
//

#include "ConstantInvokeDynamic.h"

namespace cf {

    void ConstantMethodHandleInfo::readInfo(cf::ClassReader *classReader) {
        m_referenceKind = classReader->readU1();
        m_referenceIndex = classReader->readU2();
    }

    void ConstantMethodTypeInfo::readInfo(cf::ClassReader *classReader) {
        m_descriptorIndex = classReader->readU2();
    }

    void ConstantInvokeDynamicInfo::readInfo(cf::ClassReader *classReader) {
        m_bootstrapMethodAttrIndex = classReader->readU2();
        m_nameAndTypeIndex = classReader->readU2();
    }

}