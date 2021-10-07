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
	Tabel P,A,B;
	int i; /*iterator*/
	int N; /*size dari tabel*/
	int Pos; /*posisi dari elemen*/
	int X1,X2,X3,X4; /*nilai elemen yang di cari*/
	int Byk; /*banyak elemen X pada tabel*/
	int Y; /*nilai baru elemen*/
	
	/*Algoritma*/
	
	/*################################################## TABEL PERTAMA #############################################*/
	createTable(&P);
	printf("======================================================================================\n");
	printf("==================== STATUS SEBELUM INPUT TABEL PERTAMA  =============================\n");
	printf("======================================================================================\n\n");
	printf("Tabel baru berhasil di buat.\n");
	
	/*MENGECEK APAKAH TABEL KOSONG*/
	if(isEmptyTable(P) == 1){
		printf("status: tabel masih kosong");
	}else{
		printf("status: tabel tidak kosong");
	}
	
	/*MENGECEK APAKAH TABEL PENUH*/
	if(isFullTable(P) == 1){
		printf(", tabel Penuh\n");
	}else{
		printf(", tabel tidak penuh\n");
	}
	
	/*Menghitung banyak elemen yang kosong*/
	printf("banyak elemen yang kosong pada tabel : %d\n",countEmpty(P));
	
	printf("\n======================================================================================\n");
	printf("======================================================================================\n\n");
	
	/*=========================================================================================================*/
	/*=====================================INPUT TABEL PERTAMA ================================================*/
	
	printf("Masukkan ukuran yang tabel yang di inginkan : ");
	scanf("%d", &N);
	printf("Masukkan elemen-elemen pada tabel : ");
	populateTabel(&P,N);
	
	/*=========================================================================================================*/	
	/*=========================================================================================================*/
	
	printf("\n======================================================================================\n");
	printf("==========================  STATUS SETELAH INPUT TABEL PERTAMA  ======================\n");
	printf("======================================================================================\n");
	
	/*MENGECEK APAKAH TABEL KOSONG*/
	if(isEmptyTable(P) == 1){
		printf("\nstatus: tabel masih kosong");
	}else{
		printf("\nstatus: tabel tidak kosong");
	}
	
	/*MENGECEK APAKAH TABEL PENUH*/
	if(isFullTable(P) == 1){
		printf(", tabel Penuh");
	}else{
		printf(", tabel tidak penuh");
	}
	
	/*Menghitung banyak elemen yang kosong*/
	printf("\nbanyak elemen yang kosong pada tabel : %d",countEmpty(P));
	
	printf("\nisi dari tabel pertama: ");
	printTable(P);
	printf("\nElemen terisi dari tabel pertama: ");
	viewTable(P);
	printf("\nUkuran dari tabel pertama adalah : %d",getSize(P));
	
	
	printf("\n\n======================================================================================\n");
	printf("======================================================================================\n\n");
	
	/*######################################################################################################################*/
	/*######################################################################################################################*/
	
	
	/*################################################## TABEL KEDUA #######################################################*/
	/*Membuat tabel dengan getNewTabel*/
	
	printf("======================================================================================\n");
	printf("==================== STATUS SEBELUM INPUT TABEL KEDUA  ===============================\n");
	printf("======================================================================================\n\n");
	A = getNewTable();
	
	/*Tabel kedua*/
	createTable(&A);
	printf("\n\nTabel baru berhasil di buat.\n");
	
	/*MENGECEK APAKAH TABEL KOSONG*/
	if(isEmptyTable(A) == 1){
		printf("status: tabel masih kosong");
	}else{
		printf("status: tabel tidak kosong");
	}

	/*MENGECEK APAKAH TABEL PENUH*/
	if(isFullTable(A) == 1){
		printf(", tabel Penuh\n");
	}else{
		printf(", tabel tidak penuh\n");
	};
	
	/*Menghitung banyak elemen yang kosong*/
	printf("banyak elemen yang kosong pada tabel : %d\n",countEmpty(A));
	
	printf("\n\n======================================================================================\n");
	printf("======================================================================================\n\n");
	
	
	/*=========================================================================================================*/
	/*=====================================INPUT TABEL PERTAMA ================================================*/
	
	printf("Massukan elemen-elemen pada tabel : \n");
	populateTabelMark(&A);
	
	/*=========================================================================================================*/	
	/*=========================================================================================================*/
	
	printf("\n======================================================================================\n");
	printf("==========================  STATUS SETELAH INPUT TABEL KEDUA  ==========================\n");
	printf("======================================================================================\n");

	/*MENGECEK APAKAH TABEL KOSONG*/
	if(isEmptyTable(A) == 1){
		printf("\nstatus: tabel masih kosong");
	}else{
		printf("\nstatus: tabel tidak kosong");
	}
	
	/*MENGECEK APAKAH TABEL PENUH*/
	if(isFullTable(A) == 1){
		printf(", tabel Penuh");
	}else{
		printf(", tabel tidak penuh");
	};
	
	/*Menghitung banyak elemen yang kosong*/
	printf("\nbanyak elemen yang kosong pada tabel : %d",countEmpty(A));
	
	printf("\nisi dari tabel kedua: ");
	printTable(A);
	printf("\nElemen terisi dari tabel kedua: ");
	viewTable(A);
	printf("\nUkuran dari tabel kedua adalah : %d",getSize(A));
	
	printf("\n\n======================================================================================\n");
	printf("======================================================================================\n\n");
	
	/*######################################################################################################################*/
	/*######################################################################################################################*/
	
	
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


	/*Menghitung banyak nya elemen X pada tabel pertama*/
	Byk = 0;
	printf("\n\nHitunglah banyak nilai yang ingin di hitung banyak nya: ");
	scanf("%d",&X2);
	countX(P,X2,&Byk);
	printf("Banyak element %d pada tabel ada sebanyak : %d", X2, Byk);


	
	/*Menghapus elemeen dalam tabel*/
	printf("\n\nMasukkan nilai yang ingin di hapus : ");
	scanf("%d",&X3);
	delAllX(&P,X3);
	printf("\nElemen terisi dari tabel pertama setelah nilai %d di hapus: ",X3);
	viewTable(P);
	
	/*Mengganti nilai yang di pilih dengan nilai baru*/
	printf("\n\nMasukkan nilai yang mau di ganti : ");
	scanf("%d",&X4);
	printf("Masukkan nilai baru : ");
	scanf("%d",&Y);
	updateX(&P,X4,Y);
	printf("\nElemen terisi dari tabel pertama setelah nilai di update: ");
	viewTable(P);
	
	
	return 0;
}
