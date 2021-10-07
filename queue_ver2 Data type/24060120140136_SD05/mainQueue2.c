/***********************************/
/* Program   : mainQueue2.c */
/* Deskripsi : aplikasi dari realisasi tqueue2.c */
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 30-9-2021*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"


int main() {
	/*Kamus*/
	tqueue2 A,B;
	char E; /*penampung dequeue*/
	
	
	/*Algoritma*/
	createQueue2(&A);
	printQueue2(A);
	if(isEmptyQueue2(A)){
		printf("\nQueue A kosong");
	}else{
		printf("\nQueue A tidak kosong");
	}
	
	/*di lakukan enqueue*/
	printf("\n");
	enqueue2(&A,'B');
	enqueue2(&A,'E');
	enqueue2(&A,'N');
	if(isFullQueue2(A)){
		printf("Queue A full");
	}else{
		printf("\nQueue A tidak full");
	}
	printf("\n");
	printf("Ukuran dari queue A = %d",sizeQueue2(A));
	printf("\nIsi dari queue A : ");
	viewQueue2(A);
	printf("\nNilai Head queue A = %d",Head2(A));
	printf("\nNilai Tail queue A = %d",Tail2(A));
	
	printf("\nNilai infoHead queue A = %c",infoHead2(A));
	printf("\nNilai infoTail queue A = %c",infoTail2(A));
	if(isTailStop2(A)){
		printf("\nqueue A tidak dapat lagi di isi");
	}else{
		printf("\nqueue A masih bisa di isi");
	}
	
	
	dequeue2(&A,&E);
	printf("\n\nNilai yang di dequeue dari queue A : %c",E);
	printf("\nIsi dari queue saat ini : ");
	printf("\nNilai Head queue A = %d",Head2(A));
	printf("\nNilai Tail queue A = %d",Tail2(A));
	enqueue2(&A,'H');
	enqueue2(&A,'A');
	resetHead2(&A);
	printf("\nIsi queue A setelah di resetHead : ");
	printQueue2(A);
	printf("\nNilai Head queue A = %d",Head2(A));
	printf("\nNilai Tail queue A = %d",Tail2(A));
	printf("\nNilai infoHead queue A = %c",infoHead2(A));
	printf("\nNilai infoTail queue A = %c",infoTail2(A));
	printf("\nIsi dari queue A : ");
	viewQueue2(A);
	
	printf("\n");
	createQueue2(&B);
	enqueue2(&B,'X');
	if(isOneElement2(B)){
		printf("\nHanya terdapat satu element pada queue B");
	}else{
		printf("\nTidak terdapat satu element pada queue B");
	}
	printf("\nIsi dari queue B : ");
	viewQueue2(B);
	
	return 0;
}
