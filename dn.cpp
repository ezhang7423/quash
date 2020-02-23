#pragma once

class dnode
{
private:
    int index;
    int count;
    int value;
    // forward pointer
    dnode *next;
    // backward pointer
    dnode *previous;

public:
    // constructor
    dnode(int value = 0, int index = 0, int count = 0, dnode *past = nullptr, dnode *link = nullptr)
    {
        this->index = index;
        this->value = value;
        this->count = count;
        next = link;
        previous = past;
    }
    // mutators
    void set_index(const int item) { index = item; }
    void set_value(const int val) { value = val; }

    void set_count(const int counte) { count = counte; }
    void set_link(dnode *link) { next = link; }
    void set_linkb(dnode *link) { previous = link; }

    // observers

    int ind() { return index; }
    int val() { return value; }

    int ct() { return count; }
    //  TWO FUNCTIONS TO RETRIEVE THE LINK
    dnode *nextt() { return next; }
    dnode *prev() { return previous; }
};