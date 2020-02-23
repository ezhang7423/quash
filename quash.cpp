#include "dn.cpp"

class Quash
{
public:
    void insert(int i);
    void lookup(int i);
    void deleteMin();
    void delet(int i);
    void print();
    void updateIndex(int val, int newIndex);
    friend void minsert(Quash *q, int val);
    int *bT() { return &bt[0]; };

    int len() { return length; }
    void set_len(int i) { length = i; }

private:
    dnode *find(int val);
    int bt[10000];
    dnode *ht[43];
    int length;
};