//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_OPERANDSTRACK_H
#define JVM_OPERANDSTRACK_H


namespace rt {
    class OperandStack {
    private:
        int size;
        long *slots;//win64位除外
    public:
        OperandStack* newOperandStrack(int maxStack);
        void pushInt(long val); //java int
        long popInt();
        void pushLong(long long val); //java long
        long long popLong();
        void pushFloat(float val);
        float popFloat();
        void pushDouble(double val);
        double popDouble();
        void pushRef(void* ptr);
        void* popRef();
        void pushSlot(long slot);
        long popSlot();
    };
}


#endif //JVM_OPERANDSTRACK_H
