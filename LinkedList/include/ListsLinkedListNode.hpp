#ifndef LISTSLINKEDLISTNODE_HPP
#define LISTSLINKEDLISTNODE_HPP

#include "NumbersLinkedList.hpp"

class ListsLinkedListNode
{
    public:
        ListsLinkedListNode();
        NumbersLinkedList* veri;
        ListsLinkedListNode *sonraki;
        ListsLinkedListNode(NumbersLinkedList *veri);
        ListsLinkedListNode(NumbersLinkedList* veri, ListsLinkedListNode* sonraki);
};

#endif