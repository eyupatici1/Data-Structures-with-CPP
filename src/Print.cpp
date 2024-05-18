//Gerekli includelar ekleniyor.
#include "Print.hpp"

//Kurucu metod
Print::Print(ListsLinkedList* listsLinkedList)
{
    this->listsLinkedList = listsLinkedList;
}

//Satırlara göre üst ve alt listeler yazdırılıyor.
void Print::printRows(int i) 
{
    this->listsLinkedList->indextekiEleman(i)->print();
}