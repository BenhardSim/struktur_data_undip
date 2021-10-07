/* Program   : mainTabel.c*/
/* Deskripsi : Aplikasi dari Realisasi dari tabel.c*/
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 7 September 2021*/
/***********************************/

#include <stdio.h>
#include "tabel.h"
#include "boolean.h"

int main(){
	/*Kamus Global*/
	Tabel P,B;
	int i; /*iterator*/
	int N; /*size dari tabel*/
	int Pos; /*posisi dari elemen*/
	int X1,X2,X3,X4,X5; /*nilai elemen yang di cari*/
	int Byk; /*banyak elemen X pada tabel*/
	int Y; /*nilai baru elemen*/

	/*Algoritma*/

	/*MENGECEK APAKAH TABEL KOSONG*/
	if(isEmptyTable(P) == 1){
		printf(" masih kosong");
	}else{
		printf("tidak kosong");
	}

	/*MENGECEK APAKAH TABEL PENUH*/
	if(isFullTable(P) == 1){
		printf("enuh\n");
	}else{
		printf("tidak penuh\n");
	}



	printf("Masukkan ukuran yang tabel yang di inginkan : ");
	scanf("%d", &N);
	printf("Masukkan elemen-elemen pada tabel : ");
	populateTabel(&P,N);


	/*Mencari nilai pada tabel pertama*/
	Pos = 1;
	printf("\n\nMassukan nilai yang ingin di cari posisinya pada tabel pertama: ");
	scanf("%d",&X1);
	searchX1(P,X1,&Pos);
	if(Pos != -999){
		printf("Posisi dari elemen %d terdapat pada indeks ke-%d",X1,Pos);
	}else{
		printf("nilai %d tidak terdapat dalam tabel",X1);
	}


	Byk = 0;
	printf("\n\nHitunglah banyak nilai yang ingin di hitung banyak nya: ");
	scanf("%d",&X2);
	countX(P,X2,&Byk);
	printf("Banyak element %d pada tabel ada sebanyak : %d", X2, Byk);


	printf("\n\nMasukkan nilai yang ingin di hapus pada tabel pertama : ");
	scanf("%d",&X3);
	delAllX(&P,X3);
	printf("\nElemen terisi dari tabel pertama setelah nilai %d di hapus: ",X3);
	viewTable(P);


	printf("\n\nMasukkan nilai yang mau di ganti pada tabel pertama: ");
	scanf("%d",&X4);
	printf("Masukkan nilai baru : ");
	scanf("%d",&Y);
	updateX(&P,X4,Y);
	printf("\nElemen terisi dari tabel pertama setelah nilai di update: ");
	viewTable(P);
}
