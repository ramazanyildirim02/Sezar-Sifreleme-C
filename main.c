#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct isimler{
	char ad[20];
	char soyad[20];
}ad;

void sezarSifre(char *x, int kaydirma);
void dosyayaz(char a[]);
void dosyaoku(char a[]);
void enbuyukasal(int sayi,int *ab);
void sezardanNormale(char *x, int kay);
int SezarKaydirma(int no);

int main() {
	
	int okulno,asal,ab;
	char birlestirilmisIsim[40]="";
	
	printf("MERHABA\n\n");
	printf("Adinizi girin:");
	gets(ad.ad);
	printf("Soyadinizi girin:");
	gets(ad.soyad);
	
	strcat(birlestirilmisIsim,ad.ad);
	strcat(birlestirilmisIsim," ");
	strcat(birlestirilmisIsim,ad.soyad);
	
	printf("\n\nOgrenci Numaranizi Giriniz=");
    scanf("%d",&okulno) ;
    
    int kaydirmaRakam = SezarKaydirma(okulno);
	
	sezarSifre(birlestirilmisIsim,kaydirmaRakam);
	
	dosyayaz(birlestirilmisIsim);
    
    enbuyukasal(okulno,&ab);
    
    git: printf("\nOgrenci Numaranizin En Buyuk Asal Carpani Nedir?:");
    scanf("%d",&asal); 
    
   if(ab == asal){
   	
   		printf("\n\n*******************************");
   		printf("\n\nSEZAR SIFRELI AD VE SOYAD=");
   		dosyaoku(birlestirilmisIsim);
   	
   	sezardanNormale(birlestirilmisIsim, kaydirmaRakam);
   	
   		printf("\nNORMAL AD VE SOYAD=%s",birlestirilmisIsim);
   	
		printf("\nOKUL NO=%d",okulno);
		printf("\n\n*******************************");	
   }
   
   else{
   		printf("\nGIRDIGINIZ EN BUYUK ASAL SAYI YANLIS!\n");
   		goto git;
   }
   
	return 0;
}
//Fonksiyonlar

//Bu fonksiyonda al�nan ��renci numaras�n�n son rakam�na g�re ad ve soyad sezar �ifrelemeye g�re kayd�r�lm��t�r.
void sezarSifre(char *x, int kaydirma){
	
	while(*x != '\0'){
		*x=*x+kaydirma;
		*x++;
	}	
}

//Bu fonksiyonda sezar �ifreli ad ve soyad "txt" uzant�l� dosyaya yazd�r�lm��t�r.
void dosyayaz(char a[]){
	
	FILE *sezz;

    if ((sezz = fopen ("sifrelimetin.txt", "w")) == NULL) {
         printf("Dosya acilamiyor.");
         exit(1);
    }
    else{
    	 fprintf(sezz,"%s",a);
	}
    
    fclose(sezz);	
}

//Bu fonksiyonda al�nan okul numaras�n�n en b�y�k asal �arpan� bulunuyor.
void enbuyukasal(int sayi,int *ab){
	
    int i;
	for(i=2;sayi>1;i++)
 {
  while(sayi%i == 0) {
   *ab=i;
   sayi=sayi/i;
  } 
 }	
}

//Bu fonksiyonda "txt" uzant�l� dosyada bulunan �ifreli ad ve soyad okutuluyor.
void dosyaoku(char a[]){
	
	FILE *sezz;

    if ((sezz = fopen ("sifrelimetin.txt", "r")) == NULL) {
         printf("Dosya acilamiyor.");
         exit(1);
    }
    else{
    	
    fscanf(sezz,"%s",a);
    printf("%s",a);
 
	}
    
    fclose(sezz);	
}

//Bu fonksiyonda sezar �ifreli ad ve soyad normal haline d�n��t�r�l�yor.
void sezardanNormale(char *x, int kay)
{
	while(*x != '\0'){
		*x=*x-kay;
		*x++;
	}
}

//Bu fonksiyonda okul numaras�n�n sondan 0 olmayan rakam� al�n�yor.
int SezarKaydirma(int no){
	int anahtar = 0;
	
	while(anahtar == 0){
		anahtar = no % 10;
		no = no/10;
	}
	return anahtar;
	
}
 
