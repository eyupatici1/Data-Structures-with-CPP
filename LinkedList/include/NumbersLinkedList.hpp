#ifndef NUMBERSLINKEDLIST_HPP
#define NUMBERSLINKEDLIST_HPP

#include "NumbersLinkedListNode.hpp"
#include <iomanip>

 class NumbersLinkedList
 {

    public:
        NumbersLinkedListNode* ilk;
        int boyut;
        NumbersLinkedList();
        ~NumbersLinkedList();
        void indexIleSil(int i);
        friend ostream& operator<<(ostream& ekran, NumbersLinkedList sl);
        NumbersLinkedListNode* oncekiniBul(int i);
        void ekle(const int& veri);
        void indexIleEkle(int i, const int& veri);
        const int& indextekiEleman(int i);
        int toplamDugum() const;
        bool bosMu() const;
        int toplamBoyut() const;

        void print();

 };

 #endif