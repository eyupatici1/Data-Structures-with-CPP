#ifndef LISTSLINKEDLIST_HPP
#define LISTSLINKEDLIST_HPP

#include "ListsLinkedListNode.hpp"


class ListsLinkedList
{
    private:
        ListsLinkedListNode* ilk;
        int boyut;

    public:
        ListsLinkedList();
        ~ListsLinkedList();
        ListsLinkedListNode* oncekiniBul(int i);
        ListsLinkedListNode* pozisyonBul(int i);
        NumbersLinkedList*& indextekiEleman(int i);
        ListsLinkedListNode* findIndex(int i);
        void indexIleEkle(int i, NumbersLinkedList*& veri);
        void ekle(NumbersLinkedList*& veri);
        void indexIleSil(int i);
        bool bosMu() const;
        int toplamBoyut() const;
        void swap(ListsLinkedListNode* a, ListsLinkedListNode* b);
        double average();
};

#endif 