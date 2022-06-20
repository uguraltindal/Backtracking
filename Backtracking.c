#include <stdio.h>
#include <stdlib.h>

int count=0;  // S�n�r kontrol� i�in tan�mland�..
void backT(int **matris,int N,int i,char **m,int count2);


void print(int **matris,int N,char **m)
{
	int i,j;
	printf("\n\n");	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(matris[i][j]==1)      m[i][j]='K'; // K�rm�z� renkler i�in 1 de�erini atad�k.
			else if(matris[i][j]==2) m[i][j]='Y'; // Ye�il renkler i�in 2 de�erini atad�k.
			else if(matris[i][j]==3) m[i][j]='S'; // Sar� renkler i�in 3 de�erini atad�k.
			else if(matris[i][j]==4) m[i][j]='P'; // Pembe renkler i�in 4 de�erini atad�k.
			else if(matris[i][j]==5) m[i][j]='M'; // Mavi renkler i�in 5 de�erini atad�k.
			else if(matris[i][j]==6) m[i][j]='G'; // Gri renkler i�in 6 de�erini atad�k.
			else if(matris[i][j]==7) m[i][j]='B'; // Beyaz renkler i�in 7 de�erini atad�k.
			else if(matris[i][j]==8) m[i][j]='L'; // Lacivert renkler i�in 8 de�erini atad�k.
			
			printf("   %c   ",m[i][j]);
		}
		printf("\n\n");
	}
}
void shift(int **matris,int N,int i,char **m,int count2)    // Shift fonksiyonu 
{
	int j;
	int temp=matris[i][N-1];			// backT fonksiyonundan d�nd�r�l�r.Bulunalan sat�r�n �st sat�rlar�yla uyu�mas� halinde shift yap�lmas� i�in bu fonksiyona g�nderilir.
	for(j=N-1;1<=j;j--)
	{
		matris[i][j]=matris[i][j-1];	// Son index basa d�nece�i i�in tempte kaydedilir.Di�er indexler s�rayla birbirlerine kayd�r�l�r.
		 
	}
	matris[i][0]=temp;					// En son index en bastaki index'e atan�r ve backT fonksiyonuna geri yollan�r.(Matris bilgisi de�i�ti.)
	backT(matris,N,i,m,count2);
}

void backT(int **matris,int N,int i,char **m,int count2)
{
	int j;
	int tempi=i;				// Tempi = Bulunulan i�lem yap�lan index (�rne�in tempi = 1 ise matris[1][] matris[1][] matris[1][] matris[1][] i�in i�lemler yap�l�yordur.
	if(count>(N*N)+1)			// S�n�r� a�t��� i�in sonuc olmad��� anla��ld�. Recursive fonksiyonun bitme ko�ullar�ndan SONUC YOK durumu.
	{
		printf("\n\n NO RESULT ! \n\n\n");
		exit(0);
	}
	else if(tempi==N)			// Sat�r �st sat�rlarla do�ru bi�imde s�raland���nda backT(matris,N,tempi+1,m,count2); recursive olarak kendine d�nerek 
	{							// 							Dikkat edecek olursak do�ru bi�imde s�raland��� i�in i index'ini tempi+1 diyerek bir alt sat�ra ge�mi�tik.	
		printf("	\n 	RESULT :  	");		// tempi'nin N'e e�it olmas� demek t�m elemanlar�n alt alta do�ru �ekilde s�raland���n� bize s�yl�yor ve SONUC VAR
		print(matris,N,m);						// D�nerek matrisin son halini yazd�r�yor.
		exit(1);
	}
	for(j=0;j<N;j++)
	{
		for(i=tempi;i!=0;i--)
		{
			if(matris[tempi][j]==matris[i-1][j])		// �st sat�rlarla uyu�ma kontrol�
			{
				
				
				count++;								// her shift sonras� genel count artar ve s�n�r a��m� kontorl� yap�l�r.
				count2++;								// ara bilgilendirme yaz�lar� i�in count
				if(count2==N && tempi>1)
				{
					printf("\n\n Line %d cannot be set. Returning to the top line with Backtracking..",tempi+1);
					count2=0;
					shift(matris,N,tempi-1,m,count2);			// N e�it 4 i�in 4 kere shift edilmesi demek o sat�r�n ilk haline d�nmesi demek bu y�zden bu kontrol sonras�
				}												// backtrackingi i�lemi olarak tempi-1 yani i'yi azaltarak geri d�nd�r�yoruz. shiftlenip i-1 olarak backT yollanm�� oluyor.
				printf("\n Line %d, Shifted %d times -- ",tempi+1,count2);
				shift(matris,N,tempi,m,count2);
				
				
			}
			
		}
		
	}
	print(matris,N,m);printf("	The current status of the program is as above. Line %d adjusted and printed according to the top lines.. \n\n",tempi+1);
	printf("\n------------------------------------------------------------------------------------------------------\n");
	count2=0;
	backT(matris,N,tempi+1,m,count2);		// Bulunulan sat�r�n �st sat�rlarla ayn� de�er �art� olmamas�yla alt sat�ra ge�tik (tempi+1)
	
}




void charmatris(int **matris,int N)			// kullan�c�n�n renkleri harf olarak girip say�ya d�n��t�r�ld��� yer
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
			printf("  Matris[%d][%d] : ",i,j); // hangi satir sutun de�eri girildi�ini kullan�c�ya g�sterdi.
			scanf(" %c",&temp); // her sat�r sutun i�in girdi ald�
			
			if(temp=='K' || temp=='k')      matris[i][j]=1; 		// K�rm�z� renkler i�in 1 de�erini atad�k.
			else if(temp=='Y' || temp=='y') matris[i][j]=2; // Ye�il renkler i�in 2 de�erini atad�k.
			else if(temp=='S' || temp=='s') matris[i][j]=3; // Sar� renkler i�in 3 de�erini atad�k.
			else if(temp=='P' || temp=='p')	matris[i][j]=4; // Pembe renkler i�in 4 de�erini atad�k.
			else if(temp=='M' || temp=='m')	matris[i][j]=5; // Mavi renkler i�in 5 de�erini atad�k.
			else if(temp=='G' || temp=='g') matris[i][j]=6; // Gri renkler i�in 6 de�erini atad�k.
			else if(temp=='B' || temp=='b')	matris[i][j]=7; // Beyaz renkler i�in 7 de�erini atad�k.
			else if(temp=='L' || temp=='l')	matris[i][j]=8; // Lacivert renkler i�in 8 de�erini atad�k.
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
	matc=(char**)malloc(N*sizeof(char*));			// Genel tan�mlamalar.
	matris=(int**)malloc(N*sizeof(int*));			
	for(i=0;i<N;i++)
	{
		matc[i]=(char*)malloc(N*sizeof(char));
		matris[i]=(int*)malloc(N*sizeof(int));
	}
	charmatris(matris,N);						// Girdi al�m� i�in g�nderilen fonksiyon.
	backT(matris,N,1,matc,count2);				// Gerisi recursive olarak backT ve shift aras�nda gidip geliyor.
	return 0;
}
