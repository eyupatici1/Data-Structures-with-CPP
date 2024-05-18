//Header ve diğer gerekli include'lar ekleniyor.
#include "ListsLinkedList.hpp"
#include <string>
#include <cmath>

//Kurucu metod ile ilk değerler atanıyor.
ListsLinkedList::ListsLinkedList()
{
    ilk = nullptr;
    boyut = 0;
}

//Yıkıcı metod ile çöp oluşması engelleniyor.
ListsLinkedList::~ListsLinkedList()
{
    //Geçici bir değişkene ilk değer atanarak liste gezilmesi sağlanıyor.
    ListsLinkedListNode* temp = ilk;

    //Bütün liste dolaşılıyor.
    while(!bosMu())
    {
        ilk = ilk -> sonraki;
        boyut--;
        //Silme işlemi gerçekleştiriliyor.
        delete temp;
        ilk = temp;
    }
}

//Toplam boyut döndürülüyor.
int ListsLinkedList::toplamBoyut() const
{
    return boyut;
}

//Liste boş mu kontrol ediliyor.
bool ListsLinkedList::bosMu() const
{
    if(boyut == 0)
        return true;

    return false;
}

//Diğer listedeki gibi indexteki elemanı bulmak için yardımcı fonksiyon
ListsLinkedListNode* ListsLinkedList::oncekiniBul(int i)
{
    ListsLinkedListNode* temp = ilk;
    int j = 1;
    for(ListsLinkedListNode* iterator = ilk; iterator -> sonraki != NULL && j != i; iterator = iterator ->sonraki, j++)
    {
        temp = temp ->sonraki;
    }
    return temp;
}

//Ekleme yapmak için yardımcı fonksiyon
void ListsLinkedList::indexIleEkle(int i, NumbersLinkedList*& veri)
{
    if (i == 0) {
        ilk = new ListsLinkedListNode(veri, ilk);
    } else {
        ListsLinkedListNode *prv = oncekiniBul(i);
        prv->sonraki = new ListsLinkedListNode(veri, prv->sonraki);
    }
    boyut++;
}

//Ekle fonksiyonu
void ListsLinkedList::ekle(NumbersLinkedList*& veri)
{
    indexIleEkle(boyut, veri);
}

//Verilen indexin pozisyonunu bulan fonksiyon
ListsLinkedListNode* ListsLinkedList::pozisyonBul(int i)
{
    return this -> oncekiniBul(i + 1);
}

//İndexteki elemanı diğer listeden getiren yardımcı fonksiyon
NumbersLinkedList*& ListsLinkedList::indextekiEleman(int i)
{
    if(i == 0)
    {
        return ilk -> veri;
    }

    return oncekiniBul(i)->sonraki->veri;
}

//İndex döndüren fonksiyon
ListsLinkedListNode* ListsLinkedList::findIndex(int i)
{
    if(i == 0)
    {
        return ilk;
    }

    return oncekiniBul(i)->sonraki;
}

//Swap işlemi için fonksiyon
void ListsLinkedList::swap(ListsLinkedListNode* a, ListsLinkedListNode* b) 
{

    std::swap(a, b);

}

//Ortalama hesaplanıyor.
double ListsLinkedList::average() 
{
    double maxAverageUst = 0;
    double maxAverageAlt = 0;
    double maxTotal = 0;
    ListsLinkedListNode* temp = ilk;
    int boyut = this->toplamBoyut();
    int maxNodes = temp -> veri -> toplamDugum();
    //cout<<"Max nodes rn: "<<maxNodes<<endl;

    while(temp -> sonraki) 
    {
        int tmp = temp -> veri -> toplamDugum();
        temp = temp -> sonraki;
        if(tmp > maxNodes) maxNodes = tmp;
    } 
        
    //cout<<"Max nodes avaliable is: "<<maxNodes<<endl;
        

    for(int i = 0; i < maxNodes; i++) 
    {
        double totalHere = 0;
        double averageHere = 0;
        int sayac = 0;
        temp = ilk;

        for(int j = 0; j < boyut / 2; j++) 
        {
            int current = temp -> veri -> indextekiEleman(i);
            if(current == 10) {
                //cout<<current<<endl;
                temp = temp -> sonraki;
            }
            else {
                totalHere += current;
                //cout<<current<<endl;
                sayac++;
                temp = temp -> sonraki;
            }
        }

        averageHere = totalHere / sayac;
        //cout<<"Average here is: "<<averageHere<<endl;
        maxAverageUst += averageHere;

    }

    for(int i = 0; i < maxNodes; i++) 
    {
        double totalHere = 0;
        double averageHere = 0;
        int sayac = 0;
        temp = ilk;

        for(int k = 0; k < boyut / 2; k++) 
        {
            temp = temp -> sonraki;
        }

        for(int j = 0; j < boyut / 2; j++) 
        {
            int current = temp -> veri -> indextekiEleman(i);
            if(current == 10) {
                //cout<<current<<endl;
                temp = temp -> sonraki;
            }
            else {
                totalHere += current;
                //cout<<current<<endl;
                sayac++;
                temp = temp -> sonraki;
            }
        }

        averageHere = totalHere / sayac;
        //cout<<"Average here is: "<<averageHere<<endl;
        maxAverageAlt += averageHere;

    }
    
    cout<<"Ust: "<<maxAverageUst<<endl;
    cout<<"Alt: "<<maxAverageAlt<<endl;

}