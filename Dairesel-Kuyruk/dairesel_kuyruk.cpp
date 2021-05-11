#include<iostream>
#define size 10 //kuyruk boyutunu belirler.
using namespace std;
class kuyruk {//kuyruk class'ı dır.
public:
int on,arka;//kuyruğun ön ve arka elemanını gösterir.
int kuyrukDizi[size];//kuyruk dizisi yaratılır.
kuyruk(){//kuyruk yapıcı fonksyonudur.Nesne yaratıldığı anda çalışır ve on arka değerlerine -1 atar.
on = -1;
arka= -1;
}
void ekle(int);
void cikar();
void ekranaYaz();
};
void kuyruk::ekle(int x){//kuyruğa eleman ekleme fonksyonudur.
if(on==size-1){//eğer kuyruğun ön tarafı boyuttan bir eksik ise kuyruk dolu demektir.Bir eksiği olmasının sebebi dizinin sıfırıncı indisten başlamasıdır.

cout<<"Kuyruk dolu..."<<endl;
}
else{//kuyruk dolu değil ise çalışır.
kuyrukDizi[++on]=x;//önce ön değerinin arttırır ve arttırılmiş indise atama yapar.
if(arka== -1){//ekleme işlemi sonrası diziye ilk defa eleman ekleniyorsa çalışır ve arka indisi sıfır yapar.
arka=0;
}
}
}
void kuyruk::cikar(){//çıkarma fonksiyonudur.
if(on == -1){//on indis -1 eşit ise kuyruk tamamen boş demektir.
cout<<"kuyruk tamamen bos"<<endl;
}
else{//kuyruk boş değil ise çalışır.
if(on==arka)//on ve arka değerler birbirine eşit ise kuyrukta tek değer vardı buna göre silme işlemi yapar.
on=arka=-1;
else//kuyrukta birden fazla değer var ise silme islemini yapar.
arka++;
}
}
void kuyruk::ekranaYaz(){//ekrana yazdırma fonksyonudur.
if(on == -1){//on index -1 ise kuyruk boş demektir ekrana kuyruk boş yazdırır.
cout<<"kuyruk tamamen bos"<<endl;
}
else{//kuyruk boş değil ise çalışır bir döngü ile kuyruğu ekrana sırasıyla yazdırır.
for(int i=arka;i<=on;i++){
cout<<kuyrukDizi[i]<<" ";
}
cout<<endl;
}
}
int main(){
kuyruk q;
 q.ekle(15);
 q.ekranaYaz();
 q.ekle(25);
 q.ekranaYaz();
 q.ekle(35);
 q.ekranaYaz();
 q.ekle(45);
 q.ekranaYaz();
 q.ekle(55);
 q.ekranaYaz();
 q.ekle(55);
 q.cikar();
 q.ekranaYaz();
 q.cikar();
 q.ekranaYaz();
 q.cikar();
 q.ekranaYaz();
 q.cikar();
 q.ekranaYaz();
 q.cikar();
 q.ekranaYaz();
 q.cikar();
 q.cikar();
 q.ekle(19);
 q.ekranaYaz();
 q.cikar();
 q.ekranaYaz();
}
