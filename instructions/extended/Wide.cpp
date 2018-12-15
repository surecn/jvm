//
// Created by 郑邦国 on 2018/12/7.
//

#include "Wide.h"
#include "../loads/ILoad.h"
#include "../loads/LLoad.h"
#include "../loads/FLoad.h"
#include "../loads/DLoad.h"
#include "../loads/ALoad.h"
#include "../stores/IStore.h"
#include "../stores/LStore.h"
#include "../stores/FStore.h"
#include "../stores/DStore.h"
#include "../stores/AStore.h"
#include "../math/IINC.h"

namespace rt {

    void WIDE::fetchOperand(rt::BytecodeReader *reader) {
        u1 opcode = reader->readU1();
        switch (opcode) {
            case 0x15: {      //iload
                u4 index = (u4)reader->readU2();
                ILOAD *instruction = new ILOAD();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x16: {      //lload
                u4 index = (u4) reader->readU2();
                LLOAD *instruction = new LLOAD();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x17: {      //fload
                u4 index = (u4) reader->readU2();
                FLOAD *instruction = new FLOAD();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x18: {      //dload
                u4 index = (u4) reader->readU2();
                DLOAD *instruction = new DLOAD();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x19: {     //aload
                u4 index = (u4) reader->readU2();
                ALOAD *instruction = new ALOAD();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x36: {     //istore
                u4 index = (u4) reader->readU2();
                ISTORE *instruction = new ISTORE();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x37: {     //lstore
                u4 index = (u4) reader->readU2();
                LSTORE *instruction = new LSTORE();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x38: {     //fstore
                u4 index = (u4) reader->readU2();
                FSTORE *instruction = new FSTORE();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x39: {     //dstore
                u4 index = (u4) reader->readU2();
                DSTORE *instruction = new DSTORE();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x3a: {     //astore
                u4 index = (u4) reader->readU2();
                ASTORE *instruction = new ASTORE();
                instruction->setIndex(index);
                modifyInstruction = instruction;
                break;
            }
            case 0x84: {     //iinc
                u4 index = (u4) reader->readU2();
                IINC *iinc = new IINC();
                iinc->setIndex(index);
                iinc->setConstant(reader->readU2());
                modifyInstruction = iinc;
                break;
            }
            case 0xa9: {     //ret
                cout << "Unsupported opcode : 0x9a!" << endl;
                break;
            }
        }
    }

    void WIDE::execute(rt::Frame *frame) {
        modifyInstruction->execute(frame);
    }

}

