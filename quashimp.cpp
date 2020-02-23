#include "dn.cpp"
#include "quash.cpp"
#include <iostream>
#include <string>
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
        dnode *newItem = new dnode(item, 0, 1, 0, 0);
        head = newItem;
        return;
    }
    dnode *newItem = new dnode(item, 0, 1, 0, 0);
    newItem->set_link(head);
    head->set_linkb(newItem);
    head = newItem;
    return;
}

dnode *find(int name, dnode *pot)
{
    for (dnode *i = pot; i != nullptr; i = i->nextt())
    {
        // std::cout << i->val() << std::endl;
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
        pot = find(item);
        std::cout << "item successfully inserted, count = " << pot->ct() << std::endl;
        return;
    }
    pot->set_count(pot->ct() + 1);
    std::cout << "item already present, new count = " << pot->ct() << std::endl;
}
void Quash::lookup(int item)
{
    dnode *act = find(item);
    if (act == 0)
    {
        std::cout << "item not found" << std::endl;
        return;
    }
    std::cout << "item found, count = " << act->ct() << std::endl;
    return;
}

void Quash::deleteMin()
{
    int v = bt[0];
    delet(v, true);
}

void Quash::delet(int i, bool wasMin)
{
    dnode *a = find(i);
    if (a == 0)
    {
        if (wasMin)
        {
            std::cout << "min item not present since table is empty" << std::endl;
        }
        else
        {
            std::cout << "item not present in the table" << std::endl;
        }
        return;
    }
    if (a->ct() == 1)
    {
        int index = a->ind();
        if (find(i) == this->ht[i % 43]) // if node is head
        {
            if (a->nextt())
            {
                this->ht[i % 43] = a->nextt();
                a->nextt()->set_linkb(0);
            }
        }
        else // if node is not head
        {
            a->prev()->set_link(a->nextt());
            if (a->nextt() != 0)
                a->nextt()->set_linkb(a->prev());
        }
        delete a; //deletes from hash table
        int toDel = a->ind();
        this->bt[toDel] = this->bt[length - 1];
        heapify(this, this->bT(), toDel, length);
        length--;
        if (length == 1){
            this->bt[1] = 0;
        }
        //deletes from minheap
        if (wasMin)
        {
            std::cout << "min item x successfully deleted" << std::endl;
        }
        else
        {
            std::cout << "item successfully deleted" << std::endl;
        }
        return;
    }
    a->set_count(a->ct() - 1);
    if (wasMin)
    {
        std::cout << "min item = x, count decremented, new count = " << a->ct() << std::endl;
    }
    else
    {
        std::cout << "item count decremented, new count = " << a->ct() << std::endl;
    }
    return;
}
void Quash::print()
{
    for (int i = 1; i < length; i++)
    {
        std::cout << bt[i] << " ";
    }
    std::cout << std::endl;
    return;
}
dnode *Quash::find(int val)
{
    int index = val % 43;
    dnode *pot = this->ht[index];
    return dn::find(val, pot);
}
