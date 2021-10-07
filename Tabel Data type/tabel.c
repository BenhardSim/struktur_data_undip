/***********************************/
/* Program   : tabel.c*/
/* Deskripsi : Realisasi dari ADT tabel*/
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 7 September 2021*/
/***********************************/

#ifndef tabel_C
#define tabel_C
#include <stdio.h>
#include <math.h>
#include "tabel.h"
#include "boolean.h"

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
	/*Kamus Lokal*/
	int i; /*iterator*/	
	
	/*Algoritma*/
	(*T).size = 0;
	for(i=1;i<=10;i++){
		(*T).wadah[i] = -999;
	}

}

/*function getNewTable() --> Tabel
	{mengembalikan tabel dengan size=0, setiap elemen wadah=-999} */
Tabel getNewTable (){
	/*Kamus Lokal*/
	Tabel T;
	int i; 
	/*Algortima*/
	T.size = 0;
	for(i=1;i<=10;i++){
		T.wadah[i]=-999;
	}
	return T;
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
	/*Kamus Lokal*/
	int i; /*iterator*/
	
	/*Algortima*/
	for(i=1;i<=10;i++){
		printf("%d ",T.wadah[i]);
	}
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
	/*Kamus Lokal*/
	int i; /*iterator*/
	
	/*Algortima*/
	for(i=1;i<=T.size;i++){
		printf("%d ",T.wadah[i]);
	}
}

/* procedure populateTabel( input/output T: Tabel, input N: integer )
{I.S.: T terdefinisi }
{F.S.: T terisi sebanyak N elemen}
{Proses: mengisi elemen wadah T dengan masukan keyboard, sebanyak N kali} 
{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTabel (Tabel *T, int N){
	/*Kamus Lokal*/
	int i; /*iterator*/
	int input;
	/*Algortima*/
	if(N > 0 && N<=10){
		(*T).size = N;
		for(i=1;i<=N;i++){
			scanf("%d",&input);
			if(input > 0){
				(*T).wadah[i] = input;
			}else{
				printf("masukkan harus positif");
				i--;
			}
		}
	}else{
		printf("size tabel harus Lebih dari 0");
	}
	
	
}

/* procedure populateTabelMark( input/output T: Tabel)
{I.S: T terdefinisi }
{F.S: T terisi sejumlah elemen }
{proses: mengisi elemen dengan masukan keyboard berulang hingga masukan bernilai <=0} */
void populateTabelMark (Tabel *T){
	/*Kamus Lokal*/
	int i; /*iterator*/
	int input; /*masukkan dari ketboard*/
	/*Algortima*/
	i = 1;
	scanf("%d",&input);
	while(input > 0 && i <= 10){
		(*T).wadah[i] = input;
		if(i == 10 ) break;
		scanf("%d",&input);
		if(input > 0) i++;
	}
	(*T).size = i;
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
	/*Kamus Lokal*/
	
	/*Algortima*/
	return T.size;
	
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
	/*Kamus Lokal*/
	int i; /*iterator*/
	int sum;/*banyak yang bekum terisi*/
	/*Algoritma*/
	sum = 0;
	for(i=1;i<=10;i++){
		if(T.wadah[i] == -999){
			sum++;
		}
	}
	return sum;
}

//PREDIKAT
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(T.size == 0){
		return True;
	}else{
		return False;
	}
	
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(T.size == 10){
		return True;
	}else{
		return False;
	}
	
}

//OPERATOR LAIN
/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi pertama ketemu X di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
	/*Kamus Lokal*/
	int i; /*iterator*/
	
	/*Algortima*/
	i = 0;
	*Pos = -999;
	if(T.size !=0){
		while(i<=10){
			if(T.wadah[i] == X){
				*Pos = i;
				break;
			}
			i++;
		} 
	}
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
	/*Kamus Lokal*/
	int i; /*iterator*/
	int sum;
	/*Algortima*/
	if(T.size != 0){
		sum = 0;
		for(i=1;i<=T.size;i++){
			if(T.wadah[i] == X){
				sum++;
			}
		}
		*Byk = sum;
	}
}

/*function getMaxElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxElm (Tabel T){
	/*Kamus Lokal*/
	int i; /*iterator*/
	int max; /*nilai terbesar*/
	/*Algortima*/
	if(T.size != 0){
		max = T.wadah[1];
		for(i=2;i<T.size;i++){
			if(T.wadah[i] > max){
				max = T.wadah[i];
			}
		}
		return max;
	}
}

/*function getMinElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil, tapi bukan -999 } */
int getMinElm (Tabel T){
	/*Kamus Lokal*/
	int i; /*iterator*/
	int min; /*nilai terbesar*/
	/*Algortima*/
	if(T.size != 0){
		min = T.wadah[1];
		for(i=2;i<T.size;i++){
			if(T.wadah[i] < min){
				min = T.wadah[i];
			}
		}
		return min;
	}
}

/*procedure delX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delX (Tabel *T, int X){
	/*Kamus Lokal*/
	int i; /*Iterator*/
	int found; /*apakah nilai X di temukan, 1 bila di temukan 0 bila tidak */
	/*Algortima*/
	if((*T).size != 0){
		i = 0;
		found = 0;
		while(i <=10){
			if((*T).wadah[i] == X || found == 1){
				(*T).wadah[i] = (*T).wadah[i+1];
				found = 1;
			}
			i++;
		}
		if(found == 1){
			(*T).wadah[(*T).size] = -999;
			(*T).size = (*T).size - 1;
		}
	}
}

/*procedure delAllX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllX (Tabel *T, int X){
	/*Kamus Lokal*/
	int i; /*iterator*/
	int jumlah; /*banyak elemen X*/
	/*Algotima*/
	if((*T).size != 0){
		countX(*T,X,&jumlah);
		for(i=1;i<=jumlah;i++){
			delX(T,X);
		}
	}
}

/*procedure updateX ( input/output T:Tabel, input X: integer, input Y: integer )
	{I.S.: T terdefinisi, Y >= 0}
	{F.S.: isi T.wadah bernilai X diganti nilainya dengan Y}
	{Proses: mengganti elemen pertama bernilai X dengan nilai Y }*/
void updateX (Tabel *T, int X, int Y){
	/*Kamus Lokal */
	int i; /*iterator*/
	/*Algortima*/
	if((*T).size != 0){
		i = 1;
		while(i<=(*T).size){
			if((*T).wadah[i] == X){
				(*T).wadah[i] = Y;
				break;
			}
			i++;
		}
	}
}



#endif
