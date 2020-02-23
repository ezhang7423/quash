#include "dn.cpp"
#include "quash.cpp"

void Quash::updateIndex(int val, int newIndex)
{
    dnode *pot = find(val);
    pot->set_index(newIndex);
}
void heapify(Quash *q, int *arr, int wrongVal, int length)
{
    int wV = arr[wrongVal];
    int lC = arr[wrongVal * 2];
    int rC = arr[wrongVal * 2 + 1];
    int tmp = 0;
    while ((wV > lC || wV > rC) && (wrongVal < length / 2))
    {
        if (lC > rC)
        {
            tmp = wV;
            arr[wrongVal] = rC;
            q->updateIndex(rC, wrongVal);
            arr[wrongVal * 2 + 1] = tmp;
            q->updateIndex(tmp, wrongVal * 2 + 1);
            wrongVal = wrongVal * 2 + 1;
        }
        else
        {
            tmp = wV;
            arr[wrongVal] = lC;
            q->updateIndex(lC, wrongVal);
            arr[wrongVal * 2] = tmp;
            q->updateIndex(tmp, wrongVal * 2);
            wrongVal = wrongVal * 2;
        }
        wV = arr[wrongVal];
        lC = arr[wrongVal * 2];
        rC = arr[wrongVal * 2 + 1];
    }
}

//percolate up
void pup(Quash *q, int *arr, int length)
{
    int wV = arr[length];
    int pI = length / 2;
    int p = arr[pI];
    while (wV < p)
    {
        arr[pI] = wV;
        q->updateIndex(wV, pI);
        arr[length] = p;
        q->updateIndex(p, length);
        length = length / 2;
        if (length == 0)
        {
            return;
        }
        wV = arr[length];
        pI = length / 2;
        p = arr[pI];
    }
    return;
}
void minsert(Quash *q, int val)
{
    q->bt[q->length] = val;
    pup(q, q->bT(), q->length);
    q->length++;
}

namespace dn
{
void insert(int item, dnode *&head)
{
    if (head == nullptr)
    {
        dnode *newItem = new dnode(item, 0, 0, 0);
        head = newItem;
        return;
    }
    dnode *newItem = new dnode(item, 0, 0, 0);
    newItem->set_link(head);
    head->set_linkb(newItem);
    head = newItem;
    return;
}

dnode *find(int name, dnode *pot)
{
    for (dnode *i = pot; i != nullptr; i = i->nextt())
    {
        if (name == i->val())
        {
            return i;
        }
    }
    return 0;
}

} // namespace dn

void Quash::insert(int item)
{
    dnode *pot = find(item);
    if (pot == 0)
    {
        dn::insert(item, this->ht[item % 43]);
        minsert(this, item);
        return;
    }
    pot->set_value(pot->val() + 1);
}

dnode *Quash::find(int val)
{
    int index = val % 43;
    dnode *pot = this->ht[index];
    return dn::find(val, pot);
}
