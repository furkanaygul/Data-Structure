#include <iostream>
using namespace std;
void EkranaYaz(int *dizi,int n){//ekrana yaz fonksyonudur.Bir döngü kurarak diziyi ekrana yazar.Gelen n değeri eleman sayısıdır.
for(int i=0;i<=n;i++)
 cout<<dizi[i]<<" ";
 cout<<endl;
}
void QS(int dizi[],int low , int high)//Esas fonksyonumuzdur.Burada low dizinin en düşük indisini, high en yüksek dizisini gösterir.
{
 int i = low;//dizinin en düşük değerini geçici i değiskenine atıyoruz.
 int j = high;//dizinin en yüksek değerini geçici j değiskenine atıyoruz.
 int pivot = dizi[(i + j) / 2]; //burada pivot dizinin orta noktasını bulmaya yarar.
 int temp;
 while (i <= j) //i indexi j indexinden küçük yada eşit olduğu sürece çalışır.
 {
 while (dizi[i] < pivot)//eğer dizinin i indisi pivottan küçük ise sonraki indisi geçilir burada amaç pivottan küçük elemanları pivot değerinin sağında toplamaktır.
 i++;

 while (dizi[j] > pivot)//eğer dizinin j indisi pivottan büyük ise sonraki indisi geçilir burada amaç pivottan büyük elemanları pivot değerinin solunda toplamaktır.
 j--;
 if (i <= j)//yukarıdaki döngü koşulları bitiğinde bu koşul çalışır.
 {
 temp = dizi[i]; //dizinin i indexli elemanını temp adında geçici bir elemanda tutar.
 dizi[i] = dizi[j];//dizinin sağ kısmına pivottan küçük elemanlar,sol kısmına ise büyük elemanları toplamak için swap(takas) işlemi yapılır.
 dizi[j] = temp;
 i++;//takas işlemi sonucunda i ve j indexleri bir sonraki indexe geçer.
 j--;
 }
 }
 if (j > low)//burada amaç pivotun sol tarafı için algoritmayı tekrardan çalıştırmak bu sayede dizinin sol tarafı kendi içinde sıralanmış olacak.
 QS(dizi, low, j);
 if (i < high)//burada amaç pivotun sağ tarafı için algoritmayı tekrardan çalıştırmak bu sayede dizinin sol tarafı kendi içinde sıralanmış olacak.
 QS(dizi, i, high);
}
int main()
{
 int dizi[] = {12, 45, 65, 98, 13, 485, 655, 478, 1111, 2325};

 int n = sizeof(dizi)/sizeof(dizi[0]);//size of fonksiyonu veri tipinin boyutunu hesaplar örneğin bir intiger veri tipinin boyutu 4byte tır.10 değişkenli bir
 //integer dizisinin boyutu 40byte tır.İkisini bölerek dizinin kaç elemanlı olduğu hedeflenmektedir.
 cout << "Oncesi :" <<endl;
 EkranaYaz(dizi, n);
 QS(dizi, 0, n);
 cout << "Sonrasi :" <<endl;
 EkranaYaz(dizi, n);
 return (0);
}
