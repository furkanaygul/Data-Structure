#include<iostream>
using namespace std;
void IS(int dizi[], int uzunluk) {/*Eklemeli Sıralama dizi içerisindeki bir girdinin ait olduğu
yere oturtularak ilerlenmesi ve bu sayede her döngüde kontrol edilmesi gereken girdi sayısını
azaltması prensibi ile çalışır.
 */
 int i, j, tmp;
 for (i = 1; i < uzunluk; i++) {
 j = i;
 while (j > 0 && dizi[j - 1] > dizi[j]) {//dizinin ilk indisinde örnek verelim j başlangıçta
//1 buna göre dizi[0] büyükse dizi[1]den iki indisin değerlerin takas işlemi yapar.
 tmp = dizi[j];//büyük olan değeri geçici bir tmp verisine atar.
 dizi[j] = dizi[j - 1];//takas işlemi gerçekleşir.
 dizi[j - 1] = tmp;//geçici olarak tutulan veri diziye geri alınır.
 j--;//j bir azaltılarak geriye doğru tekrar kontrol edilmesi amaçlanır.
 }
 }
}
void EkranaYaz(int dizi[], int uzunluk) {//ekrana yaz fonksyonudur.Bir döngü ile diziyi
//ekrana yazdırır.
 cout << "{";
 for (int i = 0; i < uzunluk; i++)
 cout << dizi[i] <<" ";
 cout << "}\n";
}
int main(int argc, char* argv[])
{
 int dizi[] = { 2,1,7,4,3,5,9,6,8,0 };
 size_t uzunluk = sizeof(dizi) / sizeof(int);//size of fonksiyonu veri tipinin boyutunu
//hesaplar örneğin bir intiger veri tipinin boyutu 4byte tır.10 değişkenli bir
 //integer dizisinin boyutu 40byte tır.İkisini bölerek dizinin kaç elemanlı olduğu
//hedeflenmektedir.
 EkranaYaz(dizi, uzunluk);
 IS(dizi, uzunluk);
 EkranaYaz(dizi, uzunluk);

 return 0;
}
