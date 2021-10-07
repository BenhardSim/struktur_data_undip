/***********************************/
/* Program   : mainQueue3.c */
/* Deskripsi : Aplikasi dari realisasi tqueue3.c */
/* NIM/Nama  : 2406012014013/Benhard Simanullang*/
/* Tanggal   : 30-9-2021*/
/***********************************/
#include <stdio.h>
#include "tqueue3.h"

int main() {
	/*Kamus*/
	tqueue3 A,B;
	char E;
	
	/*Algortima*/
	createQueue3(&A);
	printf("isi awal dari queue A : ");
	printQueue3(A);
	enqueue3(&A,'B');
	enqueue3(&A,'E');
	enqueue3(&A,'N');
	if(isFullQueue3(A)){
		printf("\nQueue A sudah Full");
	}else{
		printf("\nQueue A belum full");
	}
	printf("\nisi dari queue A setelah di isi : ");
	viewQueue3(A);
	printf("\nPosisi Head queue A = %d",head3(A));
	printf("\nPosisi Tail queue A = %d",tail3(A));
	printf("\nNilai dari Head queue A = %c",infoHead3(A));
	printf("\nNilai dari Tail queue A = %c",infoTail3(A));
	printf("\nUkuran dari queue A adalah %d",sizeQueue3(A));
	dequeue3(&A,&E);
	printf("\nNilai yang dikeluarkan dari queue A = %c",E);
	
	printf("\n\n");
	createQueue3(&B);
	if(isEmptyQueue3(B)){
		printf("Isi dari Queue B masih kosong");
	}else{
		printf("Isi dari Queue B tidak kosong");
	}
	enqueue3(&B,'X');
	printf("\nPosisi Head queue B = %d",head3(B));
	printf("\nPosisi Tail queue B = %d",tail3(B));
	printf("\nUkuran dari queue B adalah %d",sizeQueue3(B));
	if(isOneElement3(B)){
		printf("\nQueue B hanya terisi dengan satu elemen");
	}else{
		printf("\nQueue B terisi lebih dari satu elemen");		
	}
	printf("\nisi dari queue B setelah di isi : ");
	viewQueue3(B);
	
	return 0;
}
