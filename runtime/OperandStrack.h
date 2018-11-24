//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_OPERANDSTRACK_H
#define JVM_OPERANDSTRACK_H


namespace rt {
    class OperandStrack {
    private:
        int size;
        long *slot;//win64位除外
    public:
        OperandStrack* newOperandStrack(int maxStack);
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

    };
}


#endif //JVM_OPERANDSTRACK_H
