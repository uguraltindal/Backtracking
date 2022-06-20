#include <stdio.h>
#include <stdlib.h>

int count=0;  // Sýnýr kontrolü için tanýmlandý..
void backT(int **matris,int N,int i,char **m,int count2);


void print(int **matris,int N,char **m)
{
	int i,j;
	printf("\n\n");	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(matris[i][j]==1)      m[i][j]='K'; // Kýrmýzý renkler için 1 deðerini atadýk.
			else if(matris[i][j]==2) m[i][j]='Y'; // Yeþil renkler için 2 deðerini atadýk.
			else if(matris[i][j]==3) m[i][j]='S'; // Sarý renkler için 3 deðerini atadýk.
			else if(matris[i][j]==4) m[i][j]='P'; // Pembe renkler için 4 deðerini atadýk.
			else if(matris[i][j]==5) m[i][j]='M'; // Mavi renkler için 5 deðerini atadýk.
			else if(matris[i][j]==6) m[i][j]='G'; // Gri renkler için 6 deðerini atadýk.
			else if(matris[i][j]==7) m[i][j]='B'; // Beyaz renkler için 7 deðerini atadýk.
			else if(matris[i][j]==8) m[i][j]='L'; // Lacivert renkler için 8 deðerini atadýk.
			
			printf("   %c   ",m[i][j]);
		}
		printf("\n\n");
	}
}
void shift(int **matris,int N,int i,char **m,int count2)    // Shift fonksiyonu 
{
	int j;
	int temp=matris[i][N-1];			// backT fonksiyonundan döndürülür.Bulunalan satýrýn üst satýrlarýyla uyuþmasý halinde shift yapýlmasý için bu fonksiyona gönderilir.
	for(j=N-1;1<=j;j--)
	{
		matris[i][j]=matris[i][j-1];	// Son index basa döneceði için tempte kaydedilir.Diðer indexler sýrayla birbirlerine kaydýrýlýr.
		 
	}
	matris[i][0]=temp;					// En son index en bastaki index'e atanýr ve backT fonksiyonuna geri yollanýr.(Matris bilgisi deðiþti.)
	backT(matris,N,i,m,count2);
}

void backT(int **matris,int N,int i,char **m,int count2)
{
	int j;
	int tempi=i;				// Tempi = Bulunulan iþlem yapýlan index (örneðin tempi = 1 ise matris[1][] matris[1][] matris[1][] matris[1][] için iþlemler yapýlýyordur.
	if(count>(N*N)+1)			// Sýnýrý aþtýðý için sonuc olmadýðý anlaþýldý. Recursive fonksiyonun bitme koþullarýndan SONUC YOK durumu.
	{
		printf("\n\n NO RESULT ! \n\n\n");
		exit(0);
	}
	else if(tempi==N)			// Satýr üst satýrlarla doðru biçimde sýralandýðýnda backT(matris,N,tempi+1,m,count2); recursive olarak kendine dönerek 
	{							// 							Dikkat edecek olursak doðru biçimde sýralandýðý için i index'ini tempi+1 diyerek bir alt satýra geçmiþtik.	
		printf("	\n 	RESULT :  	");		// tempi'nin N'e eþit olmasý demek tüm elemanlarýn alt alta doðru þekilde sýralandýðýný bize söylüyor ve SONUC VAR
		print(matris,N,m);						// Dönerek matrisin son halini yazdýrýyor.
		exit(1);
	}
	for(j=0;j<N;j++)
	{
		for(i=tempi;i!=0;i--)
		{
			if(matris[tempi][j]==matris[i-1][j])		// üst satýrlarla uyuþma kontrolü
			{
				
				
				count++;								// her shift sonrasý genel count artar ve sýnýr aþýmý kontorlü yapýlýr.
				count2++;								// ara bilgilendirme yazýlarý için count
				if(count2==N && tempi>1)
				{
					printf("\n\n Line %d cannot be set. Returning to the top line with Backtracking..",tempi+1);
					count2=0;
					shift(matris,N,tempi-1,m,count2);			// N eþit 4 için 4 kere shift edilmesi demek o satýrýn ilk haline dönmesi demek bu yüzden bu kontrol sonrasý
				}												// backtrackingi iþlemi olarak tempi-1 yani i'yi azaltarak geri döndürüyoruz. shiftlenip i-1 olarak backT yollanmýþ oluyor.
				printf("\n Line %d, Shifted %d times -- ",tempi+1,count2);
				shift(matris,N,tempi,m,count2);
				
				
			}
			
		}
		
	}
	print(matris,N,m);printf("	The current status of the program is as above. Line %d adjusted and printed according to the top lines.. \n\n",tempi+1);
	printf("\n------------------------------------------------------------------------------------------------------\n");
	count2=0;
	backT(matris,N,tempi+1,m,count2);		// Bulunulan satýrýn üst satýrlarla ayný deðer þartý olmamasýyla alt satýra geçtik (tempi+1)
	
}




void charmatris(int **matris,int N)			// kullanýcýnýn renkleri harf olarak girip sayýya dönüþtürüldüðü yer
{
	
	int i,j;
	char temp;
	printf("\n\n  Color Table:  Red(1)  Green(2)  Yellow(3)   Pink(4)  ");
	printf("\n\n  		 Blue(5)     Gray(6)    White(7)  DarkBlue(8) ");
	printf("	 \n\n\n  For Red (K-k),  Green (Y-y)  ,Yellow (S-s)  ,Pink (P-p)  ,Blue (M-m) ,Gray (G-g),White (B-b),DarkBlue (L-l)");
	printf("\n\n\n  Please enter the colors you have determined as letters for each index: " );
	printf("\n\n");
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("  Matris[%d][%d] : ",i,j); // hangi satir sutun deðeri girildiðini kullanýcýya gösterdi.
			scanf(" %c",&temp); // her satýr sutun için girdi aldý
			
			if(temp=='K' || temp=='k')      matris[i][j]=1; 		// Kýrmýzý renkler için 1 deðerini atadýk.
			else if(temp=='Y' || temp=='y') matris[i][j]=2; // Yeþil renkler için 2 deðerini atadýk.
			else if(temp=='S' || temp=='s') matris[i][j]=3; // Sarý renkler için 3 deðerini atadýk.
			else if(temp=='P' || temp=='p')	matris[i][j]=4; // Pembe renkler için 4 deðerini atadýk.
			else if(temp=='M' || temp=='m')	matris[i][j]=5; // Mavi renkler için 5 deðerini atadýk.
			else if(temp=='G' || temp=='g') matris[i][j]=6; // Gri renkler için 6 deðerini atadýk.
			else if(temp=='B' || temp=='b')	matris[i][j]=7; // Beyaz renkler için 7 deðerini atadýk.
			else if(temp=='L' || temp=='l')	matris[i][j]=8; // Lacivert renkler için 8 deðerini atadýk.
			else 
			{
				printf("You have entered an incorrect Color-letter value, please re-enter the value for these indexes. \n");
				j--;
			}
			
			
		}
		
	}
	printf("\n\n");
}


int main(){
	int N,i,j;
	int count2=0;
	char **matc;
	int **matris;
	printf(" \n\n Please enter a matrix row-column N value between 3 and 8 : ");
	scanf("%d",&N);	
	matc=(char**)malloc(N*sizeof(char*));			// Genel tanýmlamalar.
	matris=(int**)malloc(N*sizeof(int*));			
	for(i=0;i<N;i++)
	{
		matc[i]=(char*)malloc(N*sizeof(char));
		matris[i]=(int*)malloc(N*sizeof(int));
	}
	charmatris(matris,N);						// Girdi alýmý için gönderilen fonksiyon.
	backT(matris,N,1,matc,count2);				// Gerisi recursive olarak backT ve shift arasýnda gidip geliyor.
	return 0;
}
