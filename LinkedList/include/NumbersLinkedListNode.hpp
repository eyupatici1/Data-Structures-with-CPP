#ifndef NUMBERSLINKEDLISTNODE_HPP
#define NUMBERSLINKEDLISTNODE_HPP

#include <iostream>
using namespace std;

class NumbersLinkedListNode
{
    public:
        int veri;
        NumbersLinkedListNode *sonraki;
        NumbersLinkedListNode();
        NumbersLinkedListNode(const int veri, NumbersLinkedListNode* sonraki);
        NumbersLinkedListNode(const int veri);
};

#endif