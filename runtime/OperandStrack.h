//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_OPERANDSTRACK_H
#define JVM_OPERANDSTRACK_H


namespace rt {
    class OperandStrack {
    private:
        int size;
        int *slot;

    public:

        OperandStrack* newOperandStrack(int maxStack);

        void pushInt(int val);

        int popInt();

        void pushFloat(float val);

        float popFloat();

    };
}


#endif //JVM_OPERANDSTRACK_H
