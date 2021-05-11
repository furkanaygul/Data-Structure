#include <iostream>
using namespace std;
class liste {
/*burada class tipinde liste düğümünü oluşturduk.Her düğüm bir intiger tipinde data, bir
yapıcı fonksyon ve yine başka bir
düğümü tutacak olan liste tipinde 2 adet pointerdan oluşmaktadır.Bu pointerlarda next olan
kendinden sonraki düğümün adresini
prev olan kendinden önceki düğümün adresini tutmaktadır*/
public:
int data;
liste* next;
liste* prev;
liste(int);
};
liste::liste(int deger) {
/*Liste yapıcı fonksyonu bir nesne yaratıldığında gönderilen değeri olusturulan
nesnenin datasına atar ve next ve prev değerlerine NULL atar */
data = deger; //dataya değer verisinin içindekini atar
next = prev = NULL; //nexti ve previ NULL yapar
}
class CiftBagliListe {
public:
/*Burada classta kullanılacak olan fonksiyonların tanımlamasının yaptım dış kısımca
ayrıca yazılacatır*/
 CiftBagliListe();
void Basa_ekle(int);
void Sona_ekle(int);
void Araya_ekle(int,int);
int Bastan_sil();
int Sondan_sil();
void Aradan_sil(int);
bool bos_mu();
void Ekrana_yaz();
int Boyut();
private:
liste* head;
liste* tail;
int boyut;
};

CiftBagliListe::CiftBagliListe() {
/*CiftBagliliste classının yapıcı fonksyonu head(başlamgıc düğümünü tutan
pointer),tail(kuyruk) ve boyuttan oluşmaktadır*/
head = tail = NULL; //head ve tail değerlerine NULL değerini atar
int boyut = 0; //ilk çalıştırmada boyut 0 olacağından sıfır değerini atar
}
void CiftBagliListe::Basa_ekle(int eklenen) { // Başlangıca ekleme fonksiyonundur
liste* temp = new liste(eklenen); //gelen eklenen değerini bir liste nesnesine oluşturup atar ve bu nesnenin adresini temp pointerina atar.
if (head == NULL) { //eğer head NULL değerine eşitse bu listenin boş olduğunu belirtir ve head ve tail in tempi atar.
head = tail = temp;//head ve taile tempi atar.
}
else {//eğer head NULL değerine eşitse liste boş değildir ve ekleme işlemine başlar
head->prev = temp; /*gelen değer başa ekleneceği için mevcut olan headi
gelen temp düğümü yapmam gerek yani yedi head im tem olmalı
bu yüzden head in öncesini tuttuğu pointeri temp yapar */
temp->next = head; //temp in sonrasını tutacağı pointer'a headi atar.
head = temp; //yeni headi temp yapar.
}
boyut ++; //listeye yeni bir düğüm eklendiği için boyutu bir arttırır.
}

void CiftBagliListe::Sona_ekle(int eklenen) { //sona eklemem fonksiyonudur.
liste* temp = new liste(eklenen); //gelen eklenen değerini bir liste nesnesine oluşturup atar ve bu nesnenin adresini temp pointerina atar.
if (tail == NULL) { //eğer tail NULL ise isteye ilk defa ekleme yapılacak demektir.
head = tail = temp; // head ve taile tempi atar
}
else {//liste boş değil ise burası çalışır.
tail->next = temp; //tail'in sonraki adresine temp'in adresini atar.
temp->prev = tail; //temp'in önceki adresine ise tail'i atar
tail = temp; //yeni tail temp olur.
}
boyut++;//ekleme yapıldığı için boyutu bir arttırır.
}
void CiftBagliListe::Araya_ekle(int oncesi,int eklenen) { //araya eklemem fonksiyonudur.Kullanıcıdan hangi değerden sonra ekleneceğini ve eklenen değeri ister.
if (!bos_mu()) {//listenin boş olmadığını kontrol etmek için bos_mu() fonksiyonunu çalıştır.Gelen değere göre çalışır.eğer boşşa işlem atlanır.
liste* eklenecek = new liste(eklenen); ////gelen eklenen değerini bir liste nesnesine oluşturup atar ve bu nesnenin adresini eklenen pointerina atar.
liste* temp = head; //ilgili değeri bulmak için arama yapması gerek bu yüzden head'i geçici bir temp pointerina atar.
while (temp) {//temp ile arama başlatılır.
if (temp->data == oncesi) {//eğer temp'in datası aradığım dataya eşit ise çalışır.

liste* sonraki = temp->next; //listeyi kaybetmemek için aranan değerin sonraki adresini bir "sonraki" adında pointer'a atar.
temp->next = eklenecek; //aradığım düğümün sonraki düğümüne eklenecek değeri atar.
eklenecek->next=sonraki; //eklenen değerin düğümünün next(sonraki) tuttuğu düğüme sonraki pointerini atar.
eklenecek->prev=temp; //eklenen değerin düğümünün prev'ine temp düğümünün adresini atar.
sonraki->prev = eklenecek;//sonraki düğünün öncesine de eklenecek değeri atar ve araya ekleme işlemi tamamlanır.
break;//işlem tamamlandığından while döngüsünü sonlandırır.
}
temp = temp->next;//ardığım değeri bulana kadar atama yapar.
}
}
boyut++;//eleman eklendiği için boyutu bir attırır.
}
int CiftBagliListe::Bastan_sil(){//Baştan silme fonksyonudur.
if(!bos_mu()) {//listenin boş olup olmadığını kontrol eder.Liste Boşsa çalışmaz.
liste* temp = head; //head değerini geçici bir temp düğümüne atar.

 if (head == tail) {//eğer liste tek düğümden oluşuyorsa head ve tail eşittir.Bu durumda tail NULL yapılır.

 tail = NULL;//tail NULL yapılır.
 }
 int Silinen = temp->data;//silinen değeri kullanıcıya göndermek için tutulur şuan için gereksizdir.
 head = head->next; //head'in next'ini yeni head yapar.

 delete temp;//eski head dğeri ram'den silinir.
 boyut--;//boyut bir azaltılır.

 return Silinen;//silinen değeri kullanıcıya geri döndürür.
}
return 0;
}
int CiftBagliListe::Sondan_sil() {//Sondan silme fonksyonudur.
if(!bos_mu()) {//listenin boş olup olmadığını kontrol eder.
liste* temp = head;//listenin sonunu bulmak için arama yapması gerek bunun için head temp'e atılır.

if(head->next==NULL){//eğer head'in next'i null ise liste tek düğümden oluşmaktadır.Başı da sonuda aynı olduğundan gereksiz kod eklememek adına baştan sil fonkstonunu çalıştıır.
Bastan_sil();//baştan sil fonksyonu çalışır.
}
while (temp->next!= NULL){//son düğümü bulana kadar arama yapar.
temp = temp->next;//temp'i temp'in nexti yapar.
}
 liste *onceki=temp->prev;//listeyi kaybetmemek adına sonun öncesini tutar.
onceki->next=NULL;//öncekinin next'ini null yapar bu sayede yeni son düğümüm önceki olur.
delete temp; //temp'i yani son düğümü ram'den siler.
boyut--;//boyutu bir azaltır.
}
return 0;
}
void CiftBagliListe::Aradan_sil(int silinen) {//aradan silme fonksiyonudur.
if (!bos_mu()) {//listenin boş olup olmadığını kontrol eder.
liste* temp = head;//uygun datayı bulmak için arama yapması gerek bunun için head temp'e atılır.
while (temp)//arama döngüsü
{

if ((temp->data == silinen)&&(temp->next!=NULL)){//eğer temp'in datası aradığım değerse uygun düğümü buluşum demektir.Eğer temp'in nexti null eşitse sona gelmiş demektir.
liste* onceki = temp->prev; //önceki düğümü ve sonraki düğümü tutmak için temp'in previ önceki düğümüne atanır.
liste* sonraki = temp->next; //önceki düğümü ve sonraki düğümü tutmak için temp'in nexti sonraki düğümüne atanır.
delete temp; //atamalar sonunda silme işlemi yapılır.
onceki->next = sonraki; //öncekinin next'ine sonraki atanır.
sonraki->prev = onceki;//sonrakinin prev'ine önceki atanır.
boyut--; //boyut bir azaltılır.
break;//döngü sonlandırılır.
}
temp = temp->next;//aradığım datayı bulana kadar atama yapılır.
}
}
}
bool CiftBagliListe::bos_mu() {//listenin boş olup olmadığının kontrol eder.
if (boyut <= 0)//boyut 0'dan küçük yada eşitse dizi boş demektir.
{
return true;//dizi boş ise true döndürür.

}
return false;//dizi boş değilse false döndürür.
}
void CiftBagliListe::Ekrana_yaz() {//ekrana yazdırma fonksiyonudur.
liste* temp = head; //head'i geçici bir temp düğümüne atar.
while (temp != NULL){//liste boş ise çalışmaz.
cout << temp->data << "->"; //ekrana yazar.
temp = temp->next; //atama yapar.
}
cout << "NULL"<<endl;//liste boş ise NULL yazar.
}
int CiftBagliListe::Boyut() { //boyutu gösteren fonksiyondur.
cout<<"dizi boyutu : "<<boyut<<endl;//liste boyutunu ekrana yazar.
}
int main()//main fonsyonudur.
{
CiftBagliListe* dll = new CiftBagliListe();//CiftBagliListe tipinde bir nesne yaratır ve bunun adresini bir pointera atar.

dll->Basa_ekle(15);//başa 15 ekler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Basa_ekle(711);//başa 711 ekler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Sona_ekle(42);//sona 42 ekler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Sona_ekle(54);//sona 52 ekler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Araya_ekle(711,24);//711'den sonra 24 ekler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Bastan_sil();//baştan siler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Sondan_sil();//sondan siler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Aradan_sil(15);//aradan siler.
dll->Ekrana_yaz();//ekrana yazdırır.
dll->Boyut();//ekrana liste boyutunu yazar.
return 0;
}
