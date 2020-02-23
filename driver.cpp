#include <iostream>
#include <string>
#include "quashimp.cpp"
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    //     string s = "insert 10, insert -50, insert 76, lookup 12, insert 12, lookup 12, insert 12, lookup 12, print, deleteMin, \
        // delete -50, print, delete 10, print, deleteMin, print, delete 12, deleteMin, print, deleteMin";
    //     string in;
    //     stringstream ss;
    //     stringstream bb;
    //     ss << s;
    //     getline(ss, in, ',');
    //     cout << in << endl;
    //     bb << in;
    //     cout << bb.str() << endl;
    //
    stringstream init(argv[1]);
    stringstream atomicUnit;
    string in, keyw, karg;
    Quash q;
    int arg = 0;
    while (getline(init, in, ','))
    {
        atomicUnit << in;
        atomicUnit >> keyw >> karg;
        atomicUnit.clear();
        if (keyw == "insert")
        {
            arg = stoi(karg);
            q.insert(arg);
        }
        else if (keyw == "lookup")
        {
            arg = stoi(karg);
            q.lookup(arg);
        }
        else if (keyw == "print")
        {
            q.print();
        }
        else if (keyw == "deleteMin")
        {
            q.deleteMin();
        }
        else if (keyw == "delete")
        {
            arg = stoi(karg);
            q.delet(arg, false);
        }
    }
}