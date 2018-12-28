//
// Created by 郑邦国 on 2018/12/10.
//

#include "Factory.h"
#include "math/IINC.h"
#include "comparisons/Ifcond.h"
#include "comparisons/IF_ICMP.h"
#include "comparisons/IF_ACMP.h"
#include "control/Goto.h"
#include "control/LookupSwitch.h"
#include "control/TableSwitch.h"
#include "extended/Wide.h"
#include "extended/IFNull.h"
#include "extended/IFNonNull.h"
#include "extended/GotoW.h"
#include "constants/Ipush.h"
#include "constants/SIPUSH.h"
#include "references/GET_STATIC.h"
#include "references/PUT_STATIC.h"
#include "references/GET_FIELD.h"
#include "references/PUT_FIELD.h"
#include "references/INVOKE_VIRTUAL.h"
#include "references/INVOKE_SPECIAL.h"
#include "references/NEW.h"
#include "references/CHECK_CAST.h"
#include "references/INSTANCE_OF.h"
#include <memory>

namespace rt {
    shared_ptr<Instruction> Factory::nop = make_shared<Instruction>(new NOP());
    ACONST_NULL Factory::aconst_null;
    ICONST_M1 Factory::iconst_m1;
    ICONST_0 Factory::iconst_0;
    ICONST_1 Factory::iconst_1;
    ICONST_2 Factory::iconst_2;
    ICONST_3 Factory::iconst_3;
    ICONST_4 Factory::iconst_4;
    ICONST_5 Factory::iconst_5;
    LCONST_0 Factory::lconst_0;
    LCONST_1 Factory::lconst_1;
    FCONST_0 Factory::fconst_0;
    FCONST_1 Factory::fconst_1;
    FCONST_2 Factory::fconst_2;
    DCONST_0 Factory::dconst_0;
    DCONST_1 Factory::dconst_1;
    ILOAD_0 Factory::iload_0;
    ILOAD_1 Factory::iload_1;
    ILOAD_2 Factory::iload_2;
    ILOAD_3 Factory::iload_3;
    LLOAD_0 Factory::lload_0;
    LLOAD_1 Factory::lload_1;
    LLOAD_2 Factory::lload_2;
    LLOAD_3 Factory::lload_3;
    FLOAD_0 Factory::fload_0;
    FLOAD_1 Factory::fload_1;
    FLOAD_2 Factory::fload_2;
    FLOAD_3 Factory::fload_3;
    DLOAD_0 Factory::dload_0;
    DLOAD_1 Factory::dload_1;
    DLOAD_2 Factory::dload_2;
    DLOAD_3 Factory::dload_3;
    ALOAD_0 Factory::aload_0;
    ALOAD_1 Factory::aload_1;
    ALOAD_2 Factory::aload_2;
    ALOAD_3 Factory::aload_3;

    ISTORE_0 Factory::istore_0;
    ISTORE_1 Factory::istore_1;
    ISTORE_2 Factory::istore_2;
    ISTORE_3 Factory::istore_3;
    LSTORE_0 Factory::lstore_0;
    LSTORE_1 Factory::lstore_1;
    LSTORE_2 Factory::lstore_2;
    LSTORE_3 Factory::lstore_3;
    FSTORE_0 Factory::fstore_0;
    FSTORE_1 Factory::fstore_1;
    FSTORE_2 Factory::fstore_2;
    FSTORE_3 Factory::fstore_3;
    DSTORE_0 Factory::dstore_0;
    DSTORE_1 Factory::dstore_1;
    DSTORE_2 Factory::dstore_2;
    DSTORE_3 Factory::dstore_3;
    ASTORE_0 Factory::astore_0;
    ASTORE_1 Factory::astore_1;
    ASTORE_2 Factory::astore_2;
    ASTORE_3 Factory::astore_3;

    Pop Factory::pop;
    Pop2 Factory::pop2;
    Dup Factory::dup;
    Dup_X1 Factory::dup_x1;
    Dup_X2 Factory::dup_x2;
    Dup2 Factory::dup2;
    Dup2_X1 Factory::dup2_x1;
    Dup2_X2 Factory::dup2_x2;
    Swap Factory::swap;
    IADD Factory::iadd;
    LADD Factory::ladd;
    FADD Factory::fadd;
    DADD Factory::dadd;
    ISUB Factory::isub;
    LSUB Factory::lsub;
    FSUB Factory::fsub;
    DSUB Factory::dsub;
    IMUL Factory::imul;
    LMUL Factory::lmul;
    FMUL Factory::fmul;
    DMUL Factory::dmul;
    IDIV Factory::idiv;
    LDIV Factory::ldiv;
    FDIV Factory::fdiv;
    DDIV Factory::ddiv;
    IREM Factory::irem;
    LREM Factory::lrem;
    FREM Factory::frem;
    DREM Factory::drem;
    INEG Factory::ineg;
    LNEG Factory::lneg;
    FNEG Factory::fneg;
    DNEG Factory::dneg;
    ISHL Factory::ishl;
    LSHL Factory::lshl;
    ISHR Factory::ishr;
    LSHR Factory::lshr;
    IUSHR Factory::iushr;
    LUSHR Factory::lushr;
    IAND Factory::iand;
    LAND Factory::land;
    IOR Factory::ior;
    LOR Factory::lor;
    IXOR Factory::ixor;
    LXOR Factory::lxor;
    I2L Factory::i2l;
    I2F Factory::i2f;
    I2D Factory::i2d;
    L2I Factory::l2i;
    L2F Factory::l2f;
    L2D Factory::l2d;
    F2I Factory::f2i;
    F2L Factory::f2l;
    F2D Factory::f2d;
    D2I Factory::d2i;
    D2L Factory::d2l;
    D2F Factory::d2f;

    I2B Factory::i2b;
    I2C Factory::i2c;
    I2S Factory::i2s;


    LCMP Factory::lcmp;
    FCMPL Factory::fcmpl;
    FCMPG Factory::fcmpg;
    DCMPL Factory::dcmpl;
    DCMPG Factory::dcmpg;

    map<int, string>* Factory::initInstructionNames() {
        map<int, string>* names = new map<int, string>();
        (*names)[0x00]="nop";
        (*names)[0x01]="aconst_null";
        (*names)[0x02]="iconst_m1";
        (*names)[0x03]="iconst_0";
        (*names)[0x04]="iconst_1";
        (*names)[0x05]="iconst_2";
        (*names)[0x06]="iconst_3";
        (*names)[0x07]="iconst_4";
        (*names)[0x08]="iconst_5";
        (*names)[0x09]="lconst_0";
        (*names)[0x0a]="lconst_1";
        (*names)[0x0b]="fconst_0";
        (*names)[0x0c]="fconst_1";
        (*names)[0x0d]="fconst_2";
        (*names)[0x0e]="dconst_0";
        (*names)[0x0f]="dconst_1";
        (*names)[0x10]="BIPUSH";
        (*names)[0x11]="SIPUSH";
        (*names)[0x15]="ILOAD";
        (*names)[0x16]="LLOAD";
        (*names)[0x17]="FLOAD";
        (*names)[0x18]="DLOAD";
        (*names)[0x19]="ALOAD";
        (*names)[0x1a]="iload_0";
        (*names)[0x1b]="iload_1";
        (*names)[0x1c]="iload_2";
        (*names)[0x1d]="iload_3";
        (*names)[0x1e]="lload_0";
        (*names)[0x1f]="lload_1";
        (*names)[0x20]="lload_2";
        (*names)[0x21]="lload_3";
        (*names)[0x22]="fload_0";
        (*names)[0x23]="fload_1";
        (*names)[0x24]="fload_2";
        (*names)[0x25]="fload_3";
        (*names)[0x26]="dload_0";
        (*names)[0x27]="dload_1";
        (*names)[0x28]="dload_2";
        (*names)[0x29]="dload_3";
        (*names)[0x2a]="aload_0";
        (*names)[0x2b]="aload_1";
        (*names)[0x2c]="aload_2";
        (*names)[0x2d]="aload_3";
        (*names)[0x36]="ISTORE";
        (*names)[0x37]="LSTORE";
        (*names)[0x38]="FSTORE";
        (*names)[0x39]="DSTORE";
        (*names)[0x3a]="ASTORE";
        (*names)[0x3b]="istore_0";
        (*names)[0x3c]="istore_1";
        (*names)[0x3d]="istore_2";
        (*names)[0x3e]="istore_3";
        (*names)[0x3f]="lstore_0";
        (*names)[0x40]="lstore_1";
        (*names)[0x41]="lstore_2";
        (*names)[0x42]="lstore_3";
        (*names)[0x43]="fstore_0";
        (*names)[0x44]="fstore_1";
        (*names)[0x45]="fstore_2";
        (*names)[0x46]="fstore_3";
        (*names)[0x47]="dstore_0";
        (*names)[0x48]="dstore_1";
        (*names)[0x49]="dstore_2";
        (*names)[0x4a]="dstore_3";
        (*names)[0x4b]="astore_0";
        (*names)[0x4c]="astore_1";
        (*names)[0x4d]="astore_2";
        (*names)[0x4e]="astore_3";
//        (*names)[0x4f]="nop";
//        (*names)[0x50]="nop";
//        (*names)[0x51]="nop";
//        (*names)[0x52]="nop";
//        (*names)[0x53]="nop";
//        (*names)[0x54]="nop";
//        (*names)[0x55]="nop";
//        (*names)[0x56]="nop";
        (*names)[0x57]="pop";
        (*names)[0x58]="pop2";
        (*names)[0x59]="dup";
        (*names)[0x5a]="dup_x1";
        (*names)[0x5b]="dup_x2";
        (*names)[0x5c]="dup2";
        (*names)[0x5d]="dup2_x1";
        (*names)[0x5e]="dup2_x2";
        (*names)[0x5f]="swap";
        (*names)[0x60]="iadd";
        (*names)[0x61]="ladd";
        (*names)[0x62]="fadd";
        (*names)[0x63]="dadd";
        (*names)[0x64]="isub";
        (*names)[0x65]="lsub";
        (*names)[0x66]="fsub";
        (*names)[0x67]="dsub";
        (*names)[0x68]="imul";
        (*names)[0x69]="lmul";
        (*names)[0x6a]="fmul";
        (*names)[0x6b]="dmul";
        (*names)[0x6c]="idiv";
        (*names)[0x6d]="ldiv";
        (*names)[0x6e]="fdiv";
        (*names)[0x6f]="ddiv";
        (*names)[0x70]="irem";
        (*names)[0x71]="lrem";
        (*names)[0x72]="frem";
        (*names)[0x73]="drem";
        (*names)[0x74]="ineg";
        (*names)[0x75]="lneg";
        (*names)[0x76]="fneg";
        (*names)[0x77]="dneg";
        (*names)[0x78]="ishl";
        (*names)[0x79]="lshl";
        (*names)[0x7a]="ishr";
        (*names)[0x7b]="lshr";
        (*names)[0x7c]="iushr";
        (*names)[0x7d]="lushr";
        (*names)[0x7e]="iand";
        (*names)[0x7f]="land";
        (*names)[0x80]="ior";
        (*names)[0x81]="lor";
        (*names)[0x82]="ixor";
        (*names)[0x83]="lxor";
        (*names)[0x84]="IINC";
        (*names)[0x85]="i2l";
        (*names)[0x86]="i2f";
        (*names)[0x87]="i2d";
        (*names)[0x88]="l2i";
        (*names)[0x89]="l2f";
        (*names)[0x8a]="l2d";
        (*names)[0x8b]="f2i";
        (*names)[0x8c]="f2l";
        (*names)[0x8d]="f2d";
        (*names)[0x8e]="d2i";
        (*names)[0x8f]="d2l";
        (*names)[0x90]="d2f";
        (*names)[0x91]="i2b";
        (*names)[0x92]="i2c";
        (*names)[0x93]="i2s";
        (*names)[0x94]="lcmp";
        (*names)[0x95]="fcmpl";
        (*names)[0x96]="fcmpg";
        (*names)[0x97]="dcmpl";
        (*names)[0x98]="dcmpg";
        (*names)[0x99]="IFEQ";
        (*names)[0x9a]="IFNE";
        (*names)[0x9b]="IFLT";
        (*names)[0x9c]="IFGE";
        (*names)[0x9d]="IFGT";
        (*names)[0x9e]="IFLE";
        (*names)[0x9f]="IF_ICMPEQ";
        (*names)[0xa0]="IF_ICMPNE";
        (*names)[0xa1]="IF_ICMPLT";
        (*names)[0xa2]="IF_ICMPGE";
        (*names)[0xa3]="IF_ICMPGT";
        (*names)[0xa4]="IF_ICMPLE";
        (*names)[0xa5]="IF_ACMPEQ";
        (*names)[0xa6]="IF_ACMPNE";
        (*names)[0xa7]="GOTO";
//        (*names)[0xa8]="nop";
//        (*names)[0xa9]="nop";
        (*names)[0xaa]="TABLE_SWITCH";
        (*names)[0xab]="LOOKUP_SWITCH";
//        (*names)[0xac]="nop";
//        (*names)[0xad]="nop";
//        (*names)[0xae]="nop";
//        (*names)[0xaf]="nop";
//        (*names)[0xb0]="nop";
//        (*names)[0xb1]="nop";
        (*names)[0xb2]="GET_STATIC";
        (*names)[0xb3]="PUT_STATIC";
        (*names)[0xb4]="GET_FIELD";
        (*names)[0xb5]="PUT_FIELD";
        (*names)[0xb6]="INVOKE_VIRTUAL";
        (*names)[0xb7]="INVOKE_SPECIAL";
//        (*names)[0xb8]="nop";
//        (*names)[0xb9]="nop";
//        (*names)[0xba]="nop";
//        (*names)[0xbb]="NEW";
//        (*names)[0xbc]="nop";
//        (*names)[0xbd]="nop";
//        (*names)[0xbe]="nop";
//        (*names)[0xbf]="nop";
        (*names)[0xc0]="CHECK_CAST";
        (*names)[0xc1]="INSTANCE_OF";
//        (*names)[0xc2]="nop";
//        (*names)[0xc3]="nop";
        (*names)[0xc4]="WIDE";
//        (*names)[0xc5]="nop";
        (*names)[0xc6]="IFNULL";
        (*names)[0xc7]="IFNONNULL";
        (*names)[0xc8]="GOTO_W";
        return names;
    }

    map<int, string>* Factory::s_instructionNames = initInstructionNames();


    shared_ptr<Instruction> Factory::newInstruction(byte opcode) {
        string s = (*s_instructionNames)[opcode];
        if (s != "")
            cout << "code:" << s << endl;
        else
            logError("code not support!");
        switch (opcode) {
            case 0x00:
                return &nop;
            case 0x01:
                return &aconst_null;
            case 0x02:
                return &iconst_m1;
            case 0x03:
                return &iconst_0;
            case 0x04:
                return &iconst_1;
            case 0x05:
                return &iconst_2;
            case 0x06:
                return &iconst_3;
            case 0x07:
                return &iconst_4;
            case 0x08:
                return &iconst_5;
            case 0x09:
                return &lconst_0;
            case 0x0a:
                return &lconst_1;
            case 0x0b:
                return &fconst_0;
            case 0x0c:
                return &fconst_1;
            case 0x0d:
                return &fconst_2;
            case 0x0e:
                return &dconst_0;
            case 0x0f:
                return &dconst_1;
            case 0x10:
                return new BIPUSH();
            case 0x11:
                return new SIPUSH();
                // case 0x12:
                // 	return &LDC{}
                // case 0x13:
                // 	return &LDC_W{}
                // case 0x14:
                // 	return &LDC2_W{}
            case 0x15:
                return new ILOAD();
            case 0x16:
                return new LLOAD();
            case 0x17:
                return new FLOAD();
            case 0x18:
                return new DLOAD();
            case 0x19:
                return new ALOAD();
            case 0x1a:
                return &iload_0;
            case 0x1b:
                return &iload_1;
            case 0x1c:
                return &iload_2;
            case 0x1d:
                return &iload_3;
            case 0x1e:
                return &lload_0;
            case 0x1f:
                return &lload_1;
            case 0x20:
                return &lload_2;
            case 0x21:
                return &lload_3;
            case 0x22:
                return &fload_0;
            case 0x23:
                return &fload_1;
            case 0x24:
                return &fload_2;
            case 0x25:
                return &fload_3;
            case 0x26:
                return &dload_0;
            case 0x27:
                return &dload_1;
            case 0x28:
                return &dload_2;
            case 0x29:
                return &dload_3;
            case 0x2a:
                return &aload_0;
            case 0x2b:
                return &aload_1;
            case 0x2c:
                return &aload_2;
            case 0x2d:
                return &aload_3;
                // case 0x2e:
                // 	return iaload
                // case 0x2f:
                // 	return laload
                // case 0x30:
                // 	return faload
                // case 0x31:
                // 	return daload
                // case 0x32:
                // 	return aaload
                // case 0x33:
                // 	return baload
                // case 0x34:
                // 	return caload
                // case 0x35:
                // 	return saload
            case 0x36:
                return new ISTORE();
            case 0x37:
                return new LSTORE();
            case 0x38:
                return new FSTORE();
            case 0x39:
                return new DSTORE();
            case 0x3a:
                return new ASTORE();
            case 0x3b:
                return &istore_0;
            case 0x3c:
                return &istore_1;
            case 0x3d:
                return &istore_2;
            case 0x3e:
                return &istore_3;
            case 0x3f:
                return &lstore_0;
            case 0x40:
                return &lstore_1;
            case 0x41:
                return &lstore_2;
            case 0x42:
                return &lstore_3;
            case 0x43:
                return &fstore_0;
            case 0x44:
                return &fstore_1;
            case 0x45:
                return &fstore_2;
            case 0x46:
                return &fstore_3;
            case 0x47:
                return &dstore_0;
            case 0x48:
                return &dstore_1;
            case 0x49:
                return &dstore_2;
            case 0x4a:
                return &dstore_3;
            case 0x4b:
                return &astore_0;
            case 0x4c:
                return &astore_1;
            case 0x4d:
                return &astore_2;
            case 0x4e:
                return &astore_3;
                // case 0x4f:
                // 	return iastore
                // case 0x50:
                // 	return lastore
                // case 0x51:
                // 	return fastore
                // case 0x52:
                // 	return dastore
                // case 0x53:
                // 	return aastore
                // case 0x54:
                // 	return bastore
                // case 0x55:
                // 	return castore
                // case 0x56:
                // 	return sastore
            case 0x57:
                return &pop;
            case 0x58:
                return &pop2;
            case 0x59:
                return &dup;
            case 0x5a:
                return &dup_x1;
            case 0x5b:
                return &dup_x2;
            case 0x5c:
                return &dup2;
            case 0x5d:
                return &dup2_x1;
            case 0x5e:
                return &dup2_x2;
            case 0x5f:
                return &swap;
            case 0x60:
                return &iadd;
            case 0x61:
                return &ladd;
            case 0x62:
                return &fadd;
            case 0x63:
                return &dadd;
            case 0x64:
                return &isub;
            case 0x65:
                return &lsub;
            case 0x66:
                return &fsub;
            case 0x67:
                return &dsub;
            case 0x68:
                return &imul;
            case 0x69:
                return &lmul;
            case 0x6a:
                return &fmul;
            case 0x6b:
                return &dmul;
            case 0x6c:
                return &idiv;
            case 0x6d:
                return &ldiv;
            case 0x6e:
                return &fdiv;
            case 0x6f:
                return &ddiv;
            case 0x70:
                return &irem;
            case 0x71:
                return &lrem;
            case 0x72:
                return &frem;
            case 0x73:
                return &drem;
            case 0x74:
                return &ineg;
            case 0x75:
                return &lneg;
            case 0x76:
                return &fneg;
            case 0x77:
                return &dneg;
            case 0x78:
                return &ishl;
            case 0x79:
                return &lshl;
            case 0x7a:
                return &ishr;
            case 0x7b:
                return &lshr;
            case 0x7c:
                return &iushr;
            case 0x7d:
                return &lushr;
            case 0x7e:
                return &iand;
            case 0x7f:
                return &land;
            case 0x80:
                return &ior;
            case 0x81:
                return &lor;
            case 0x82:
                return &ixor;
            case 0x83:
                return &lxor;
            case 0x84:
                return new IINC();
            case 0x85:
                return &i2l;
            case 0x86:
                return &i2f;
            case 0x87:
                return &i2d;
            case 0x88:
                return &l2i;
            case 0x89:
                return &l2f;
            case 0x8a:
                return &l2d;
            case 0x8b:
                return &f2i;
            case 0x8c:
                return &f2l;
            case 0x8d:
                return &f2d;
            case 0x8e:
                return &d2i;
            case 0x8f:
                return &d2l;
            case 0x90:
                return &d2f;
            case 0x91:
                return &i2b;
            case 0x92:
                return &i2c;
            case 0x93:
                return &i2s;
            case 0x94:
                return &lcmp;
            case 0x95:
                return &fcmpl;
            case 0x96:
                return &fcmpg;
            case 0x97:
                return &dcmpl;
            case 0x98:
                return &dcmpg;
            case 0x99:
                return new IFEQ();
            case 0x9a:
                return new IFNE();
            case 0x9b:
                return new IFLT();
            case 0x9c:
                return new IFGE();
            case 0x9d:
                return new IFGT();
            case 0x9e:
                return new IFLE();
            case 0x9f:
                return new IF_ICMPEQ();
            case 0xa0:
                return new IF_ICMPNE();
            case 0xa1:
                return new IF_ICMPLT();
            case 0xa2:
                return new IF_ICMPGE();
            case 0xa3:
                return new IF_ICMPGT();
            case 0xa4:
                return new IF_ICMPLE();
            case 0xa5:
                return new IF_ACMPEQ();
            case 0xa6:
                return new IF_ACMPNE();
            case 0xa7:
                return new GOTO();
                // case 0xa8:
                // 	return &JSR{}
                // case 0xa9:
                // 	return &RET{}
            case 0xaa:
                return new TABLE_SWITCH();
            case 0xab:
                return new LOOKUP_SWITCH();
                // case 0xac:
                // 	return ireturn
                // case 0xad:
                // 	return lreturn
                // case 0xae:
                // 	return freturn
                // case 0xaf:
                // 	return dreturn
                // case 0xb0:
                // 	return areturn
                // case 0xb1:
                // 	return _return
            case 0xb2:
                return new GET_STATIC();
             case 0xb3:
                return new PUT_STATIC();
             case 0xb4:
                return new GET_FIELD();
             case 0xb5:
                return new PUT_FIELD();
            case 0xb6:
                return new INVOKE_VIRTUAL();
             case 0xb7:
                return new INVOKE_SPECIAL();
                // case 0xb8:
                // 	return &INVOKE_STATIC{}
                // case 0xb9:
                // 	return &INVOKE_INTERFACE{}
                // case 0xba:
                // 	return &INVOKE_DYNAMIC{}
             case 0xbb:
                return new NEW();
                // case 0xbc:
                // 	return &NEW_ARRAY{}
                // case 0xbd:
                // 	return &ANEW_ARRAY{}
                // case 0xbe:
                // 	return arraylength
                // case 0xbf:
                // 	return athrow
             case 0xc0:
                return new CHECK_CAST();
             case 0xc1:
                return new INSTANCE_OF();
                // case 0xc2:
                // 	return monitorenter
                // case 0xc3:
                // 	return monitorexit
            case 0xc4:
                return new WIDE();
                // case 0xc5:
                // 	return &MULTI_ANEW_ARRAY{}
            case 0xc6:
                return new IFNULL();
            case 0xc7:
                return new IFNONNULL();
            case 0xc8:
                return new GOTO_W();
                // case 0xc9:
                // 	return &JSR_W{}
                // case 0xca: breakpoint
                // case 0xfe: impdep1
                // case 0xff: impdep2
            default:
                cout << "Unsupported opcode:" << hex << (int)opcode << endl;
                break;
                //panic(fmt.Errorf("Unsupported opcode: 0x%x!", opcode))
        }
    }

}