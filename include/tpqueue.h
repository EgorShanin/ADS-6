// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int first, last;
 public:
    TPQueue(): first(0), last(0) {}
    void push(T x) {
        if ((last % size) - (first % size) >= size) {
            int i = last++;
            while (--i >= (first % size)) {
                if (x.prior > arr[i % size].prior) {
                    arr[(i + 1) % size] = arr[i % size];
                } else {
                    break;
                }
            }
            arr[(i + 1) % size] = x;
        }
    }
    T pop() {
        return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
