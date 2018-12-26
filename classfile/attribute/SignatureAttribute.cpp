//
// Created by 郑邦国 on 2018/12/25.
//

#include "SignatureAttribute.h"

namespace cf {

    void SignatureAttribute::readInfo(cf::ClassReader *classReader) {
        m_signatureIndex = classReader->readU2();
    }

    string* SignatureAttribute::getSignature() {
        return m_cp->getUtf8(m_signatureIndex);
    }

}
