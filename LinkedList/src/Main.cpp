//Daha önce oluşturduğumuz header dosyaları include ediliyor
#include "NumbersLinkedList.hpp"
#include "ListsLinkedList.hpp"
#include "Print.hpp"
#include "File.hpp"
#include <cstdlib>

//Programın main'i
int main(int argc, char** argv) 
{

    //File sınıfından object oluşturarak dosya okuma işlemi başlatılıyor.
    File* file = new File("Sayilar.txt");
    //Toplam liste sayısı elde ediliyor.
    int lists = file -> satirSayisi() * 2;

    //Sayıların eklendiği listeyi kontrol edecek liste oluşturuluyor.
    ListsLinkedList* listsLinkedList = file -> yoneticiOlustur();
    //Kontrol amaçlı Print sınıfı
    Print* print = new Print(listsLinkedList);

    //Ortalamalar hesaplanıyor.
    listsLinkedList -> average();

    //return 0
    return 0;
}