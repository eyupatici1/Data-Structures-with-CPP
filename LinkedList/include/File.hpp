#ifndef FILE_HPP
#define FILE_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "NumbersLinkedList.hpp"
#include "ListsLinkedList.hpp"

class File {
    private: 
        string dosyaAdi;
        NumbersLinkedList **satirlar;
        void oku();
    public:
        int satirSayisi();
        File(string str);
        ~File();
        ListsLinkedList* yoneticiOlustur();
        void swap(int i, int y);

};

#endif