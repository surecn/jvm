//
// Created by 郑邦国 on 2018/11/26.
//

#include "Dup.h"

namespace rt {

    /*
    bottom -> top
    [...][c][b][a]
                 \_
                   |
                   V
    [...][c][b][a][a]
    */
    void Dup::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        long slot = stack->popSlot();
        stack->pushSlot(slot);
        stack->pushSlot(slot);
    }

    /*
    bottom -> top
    [...][c][b][a]
              __/
             |
             V
    [...][c][a][b][a]
    */
    void Dup_X1::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        long slot1 = stack->popSlot();
        long slot2 = stack->popSlot();
        stack->pushSlot(slot1);
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);
    }

    /*
    bottom -> top
    [...][c][b][a]
           _____/
          |
          V
    [...][a][c][b][a]
    */
    void Dup_X2::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        long slot1 = stack->popSlot();
        long slot2 = stack->popSlot();
        long slot3 = stack->popSlot();
        stack->pushSlot(slot1);
        stack->pushSlot(slot3);
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);
    }

    /*
    bottom -> top
    [...][c][b][a]____
              \____   |
                   |  |
                   V  V
    [...][c][b][a][b][a]
    */
    void Dup2::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        long slot1 = stack->popSlot();
        long slot2 = stack->popSlot();
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);
    }

    /*
    bottom -> top
    [...][c][b][a]
           _/ __/
          |  |
          V  V
    [...][b][a][c][b][a]
    */
    void Dup2_X1::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        long slot1 = stack->popSlot();
        long slot2 = stack->popSlot();
        long slot3 = stack->popSlot();
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);
        stack->pushSlot(slot3);
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);
    }

    /*
    bottom -> top
    [...][d][c][b][a]
           ____/ __/
          |   __/
          V  V
    [...][b][a][d][c][b][a]
    */
    void Dup2_X2::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        long slot1 = stack->popSlot();
        long slot2 = stack->popSlot();
        long slot3 = stack->popSlot();
        long slot4 = stack->popSlot();
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);
        stack->pushSlot(slot4);
        stack->pushSlot(slot3);
        stack->pushSlot(slot2);
        stack->pushSlot(slot1);

    }



}
