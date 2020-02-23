#include "dn.cpp"

class Quash
{
public:
    Quash()
    {
        length = 1;
        for (int i = 0; i < 10000; i++)
        {
            bt[i] = 0;
        }
        for (int i = 0; i < 43; i++)
        {
            ht[i] = 0;
        }
    }
    void insert(int i);
    void lookup(int i);
    void deleteMin();
    void delet(int i, bool);
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