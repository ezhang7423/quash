#pragma once

class dnode
{
private:
    int index;
    int value;
    // forward pointer
    dnode *next;
    // backward pointer
    dnode *previous;

public:
    // constructor
    dnode(int value = 0, int index = 0, dnode *past = nullptr, dnode *link = nullptr)
    {
        this->index = index;
        this->value = value;
        next = link;
        previous = past;
    }
    // mutators
    void set_value(const int item) { value = item; }
    void set_link(dnode *link) { next = link; }
    void set_linkb(dnode *link) { previous = link; }

    // observers

    int ind() { return index; }
    int val() { return value; }
    //  TWO FUNCTIONS TO RETRIEVE THE LINK
    dnode *nextt() { return next; }
    dnode *prev() { return previous; }
};