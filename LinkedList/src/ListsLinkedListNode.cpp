#include "ListsLinkedListNode.hpp"
#include <string>

//Duruma göre kullanılacak olan kurucular oluşturuluyor.
ListsLinkedListNode::ListsLinkedListNode()
{
    
}

ListsLinkedListNode::ListsLinkedListNode(NumbersLinkedList* veri, ListsLinkedListNode* sonraki) 
{
    this->veri = veri;
    this->sonraki = sonraki;
}

ListsLinkedListNode::ListsLinkedListNode(NumbersLinkedList *veri)
{
    this->veri = veri;
    this->sonraki = sonraki;
}