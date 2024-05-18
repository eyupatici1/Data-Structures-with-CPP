#ifndef PRINT_HPP
#define PRINT_HPP
#include "ListsLinkedList.hpp"

class Print
{
    private:
        ListsLinkedList* listsLinkedList;
    
    public:
        Print(ListsLinkedList* listsLinkedList);
        void printRows(int i);

};

#endif