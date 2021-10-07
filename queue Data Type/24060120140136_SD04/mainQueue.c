/* Program   : mainQueue.c */
/* Deskripsi : aplikasi prosedur dan fungsi yang terdapat pada tqueue.h */
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 21 september 2021*/
/***********************************/
#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"


int main(){
	
	/*Kamus*/
	tqueue A,B;
	char E,R; /*penampung dari dequeue*/
	
	
	/*Algoritma*/
	createQueue(&A);
	createQueue(&B);
	printQueue(A);
	printf("\n");
	enqueue(&A,'B');
	enqueue(&A,'E');
	enqueue(&A,'N');
	enqueue(&A,'H');
	enqueue(&A,'A');
	viewQueue(A);	
	
	/*mengecek apakah queue A full atau tidak*/
	printf("\nposisi dari head pada queue A adalah = %d",Head(A));
	printf("\nposisi dari tail pada queue A adalah = %d",Tail(A));
	printf("\npanjang dari queue A = %d",sizeQueue(A));
	if(isFullQueue(A)){
		printf("\nqueue A sudah terisi penuh");
	}else{
		printf("\nqueue A belum terisi penuh");
	}
	
	dequeue(&A,&E);
	printf("\n");
	printf("hasil dequeue queue A = %c\n",E);
	printf("\nposisi dari head pada queue A adalah = %d",Head(A));
	printf("\nposisi dari tail pada queue A adalah = %d",Tail(A));
	printf("\nnilai head queue A = %c",infoHead(A));
	printf("\nnilai tail queue A = %c",infoTail(A));
	printf("\npanjang queue terpanjang  = %d",maxlength(A,B));
	
	/*mengecek isi dari queue B*/
	if(isEmptyQueue(B)){
		printf("\nisi queue B kosong");
	}else{
		printf("\nqueue B tidak kosong");
	}
	
	/*memasukkan W*/
	enqueue2(&A,&B,'W');
	/*karena panjang dari B lebih pendek maka char W masuk ke queue B*/
	printf("\nisi queue A = ");
	viewQueue(A);
	printf("\nisi queue B = ");
	viewQueue(B);
	
	/*mengecek apakah queue B hanya berisi satu elemen*/
	if(isOneElement(B)){
		printf("\nqueue B hanya berisi satu elemen");
	}else{
		printf("\nqueue B tidak berisi satu elemen");
	}
	
	
	printf("\n");
	
	dequeue2(&A,&B,&R);
	/*karena A yang lebih panjang maka dequeue di lakuakn pada queue A*/
	printf("\nNilai yang di keluarkan dari queue adalah = %c",R);
	/*isi queue setelah di keluarkan */
	printf("\nisi queue A = ");
	viewQueue(A);
	return 0;
}
