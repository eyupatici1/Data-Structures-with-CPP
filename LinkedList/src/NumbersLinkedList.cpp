//Header sınıfı include ediliyor.
#include "NumbersLinkedList.hpp"

//Kurucu metodu ile ilk değerler atanıyor.
NumbersLinkedList::NumbersLinkedList()
{
    ilk = NULL;
    boyut = 0;
}

//Yıkıcı metod ile çöpler temizleniyor.
NumbersLinkedList::~NumbersLinkedList()
{
    NumbersLinkedListNode* temp = ilk;

    while(!bosMu())
    {
        ilk = ilk -> sonraki;
        boyut--;
        delete temp;
        ilk = temp;
    }
}

//Bir indexteki veriyi bulmak için yardımcı metod 
NumbersLinkedListNode* NumbersLinkedList::oncekiniBul(int i)
{
    NumbersLinkedListNode* temp = ilk;
    int j = 1;
    //Bütün liste geziliyor
    for(NumbersLinkedListNode* iterator = ilk; iterator ->sonraki != NULL && i != j; iterator = iterator ->sonraki, i++)
    {
        temp = temp->sonraki;
    }

    return temp;
}

//Toplam boyut döndürülüyor
int NumbersLinkedList::toplamBoyut() const{
    return boyut;
}

//Toplam düğüm sayısı döndürülüyor.
int NumbersLinkedList::toplamDugum() const 
{
    int total = 1;
    NumbersLinkedListNode* temp = ilk;
    //Bütün liste geziliyor.
    for(NumbersLinkedListNode* iterator = ilk; iterator -> sonraki != nullptr; iterator = iterator -> sonraki)
    {
        temp = temp -> sonraki;
        total++;
    }

    return total;
}

//Liste boş mu kontrol ediliyor.
bool NumbersLinkedList::bosMu() const
{
    if(boyut == 0)
        return true;

    return false;
}

//Listeye ekleme fonksiyonu
void NumbersLinkedList::ekle(const int& veri)
{
    indexIleEkle(boyut, veri);
}

//Listeye ekleme yapmak için yardımcı fonksiyon
void NumbersLinkedList::indexIleEkle(int i, const int& veri)
{
    if(i == 0)
    {
        ilk = new NumbersLinkedListNode(veri, ilk);
    }
    else {
        NumbersLinkedListNode* temp = oncekiniBul(i);
        temp->sonraki = new NumbersLinkedListNode(veri, temp->sonraki);
    }
    boyut++;
}

//Yazdırma işlemlerinin daha güzel görükmesi için 
ostream& operator <<(ostream& ekran, NumbersLinkedList sl) {

    //Liste geziliyor.
    for (NumbersLinkedListNode *iterator = sl.ilk; iterator != NULL; iterator = iterator->sonraki) {
        ekran<<iterator<<"\n";
        ekran<<"-----------\n";
        ekran<<"|"<<setw(5)<<iterator->veri<<setw(5)<<"|"<<endl;
        ekran<<"-----------\n";
        ekran<<"|"<<iterator->sonraki<<setw(3)<<"|\n";
        ekran<<"-----------\n\n";
    }

    //Değerler bastırılıyor.
    ekran << endl;
    return ekran;
} 

//Verilen indexteki elemanı döndüren fonksiyon
const int& NumbersLinkedList::indextekiEleman(int i)
{

    NumbersLinkedListNode* temp = ilk;

    if(i == 0)
    {
        return temp -> veri;
    }

    else 
    {
        for(int j = 0; j < i; j++) 
        {
            if(temp -> sonraki != nullptr) temp = temp -> sonraki;
            else temp -> veri = 10;
        }

        return temp -> veri;
    }

    //return oncekiniBul(i+1)->veri;
}


//Yazdırma işlemi için yardımcı fonksiyon. Adres veri ve sonraki bilgileri bastırılıyor.
void NumbersLinkedList::print() 
{
    NumbersLinkedListNode* temp = ilk;

    cout<<"--------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"Adres:"<<setw(20)<<"Veri:"<<setw(20)<<"Sonraki:"<<endl; 
    cout<<"--------------------------------------------------------------"<<endl;  

    while(temp != 0)
    {
        cout<<setw(20)<<temp<<setw(20)<<temp -> veri<<setw(20)<<temp->sonraki<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        temp = temp -> sonraki;  
    }
}