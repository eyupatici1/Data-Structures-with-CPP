//Düğüm sınıfı include ediliyor.
#include "NumbersLinkedListNode.hpp"

//Duruma göre kullanılacak olan kurucular oluşturuluyor.
NumbersLinkedListNode::NumbersLinkedListNode() 
{
    
}


NumbersLinkedListNode::NumbersLinkedListNode(const int veri, NumbersLinkedListNode* sonraki)
{
    this->veri = veri;
    this->sonraki = sonraki;
}

NumbersLinkedListNode::NumbersLinkedListNode(const int veri) 
{
    this->veri = veri;
    this->sonraki = sonraki;
}