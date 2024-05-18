//Gerekli include ekleniyor
#include "File.hpp"

//Kurucu oluşturuluyor ve sayılar okunarak listelere oluşturuluyor.
File::File(string dosyaAdi)
{
    this->dosyaAdi = dosyaAdi;
    int sayac = satirSayisi();
    this->satirlar = new NumbersLinkedList*[sayac * 2];
    for(int i = 0; i < sayac * 2; i++)
    {
        this->satirlar[i] = new NumbersLinkedList();
    }
}

//Yıkıcı metod ile çöp oluşması engelleniyor.
File::~File()
{
    if(satirlar != 0)
    {
        int sayac = satirSayisi();
        for(int i = 0; i < sayac; i++)
        {
            if(satirlar[i] != 0)
            {
                delete satirlar[i];
            }
        }
        delete[] satirlar;
    }
}

//Toplam satır sayısını bulacak metod
int File::satirSayisi()
{
    int i = 0;
    ifstream dosya(this->dosyaAdi);
    string str;
    while(getline(dosya, str))
    {
        i++;
    }
    dosya.close();
    return i;
}

//Daha önce oluşturulan listelere dosyadan okunan sayılar aktarılıyor.
void File::oku()
{
    string token;
    ifstream dosya(this->dosyaAdi);
    string s;
    int firstIndex = 0;
    int secondIndex = 0;
    int toChange = 0;
    int i = 0;
    int boyut = this->satirSayisi() * 2;
    while(getline(dosya, token))
    {
        istringstream iss(token);

        while(getline(iss, s, ' '))
        {
            int number = stoi(s);
            int firstDigit = (number / 10) % 10;
            int secondDigit = number % 10;

            this -> satirlar[i] -> ekle(firstDigit);
            this -> satirlar[i + boyut / 2] -> ekle(secondDigit);
        }

        i += 1;
    }

    //Kullanıcıdan input alınıyor.
    cout<<"Konum A: ";
    cin>>firstIndex;
    cout<<"Konum B: ";
    cin>>secondIndex;
    cout<<endl;

    //Girilen indexler alt ve üst listelerde gerekli değişiklikleri yapacak şekilde ayarlanıyor.
    if(secondIndex == 0) toChange = boyut / 2;
    else                 toChange = boyut / 2 + secondIndex;

    //Gerekli swap işlemi yapılıyor.
    this->swap(firstIndex, toChange);

    //Dosya kapatılıyor.
    dosya.close();
}

//2. Bağlı liste yani diğer listeleri kontrol edecek ve adres tutacak bağlı liste oluşturulup değerler ekleniyor.
ListsLinkedList* File::yoneticiOlustur()
{
    oku();  
    ListsLinkedList* listsLinkedList = new ListsLinkedList();
    int sayac = satirSayisi();

    for(int i = 0; i < sayac * 2; i++)
    {
        listsLinkedList -> ekle(this->satirlar[i]);
    }

    return listsLinkedList;

}

//Swap işlemi gerçekleştiriliyor.
void File::swap(int i, int y) 
{
    std::swap(satirlar[i], satirlar[y]);
}