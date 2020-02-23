#include "dn.cpp"
#include "quash.cpp"

void Quash::insert(int item)
{
}

namespace mh
{

void heapify(int *arr)
{
}
void minsert(Quash *q, int val)
{
    q->bT()[q->len()] = val;
    heapify(q->bT());
    q->set_len(q->len() + 1);
}

} // namespace mh

namespace dn
{
void insert(int item, dnode *&head)
{
    if (head == nullptr)
    {
        dnode *newItem = new dnode(item, 0, 0, 0);
        head = newItem;
        mh::minsert(item);
        return;
    }
    // print_ll(head);

    for (dnode<Word> *i = head; i != nullptr; i = i->nextt())
    {
        if (i->nextt() == nullptr)
        {
            dnode<Word> *newItem = new dnode<Word>(item, i, 0);
            i->set_link(newItem);
            return;
        }
    }
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

dnode *Quash::find(int val)
{
    int index = val % 43;
    dnode *pot = this->ht[index];
    return dn::find(val, pot);
}