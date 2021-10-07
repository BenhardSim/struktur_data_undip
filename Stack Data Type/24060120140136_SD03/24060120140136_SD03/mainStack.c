/***********************************/
/* Program   : boolean.h */
/* Deskripsi : header file modul boolean */
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : */
/***********************************/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include "boolean.h"
#include "tstack.h"

int main(){
	
	/*Kamus*/
	char X1,X2,X3;
	int i,j; /*iterator*/
	int p; /*panjang string*/
	Tstack A,B,C;
	char e;
	int div; /*mencari nilai tengah kata*/
	
	/*Kata yang akan dicari apakah palindrom atau tidak*/
	char kata[10000] = "malam";
	
	/*Algoritma*/
	
	/*Stack A*/
	createStack(&A);
	push(&A,'B');
	push(&A,'E');
	push(&A,'N');
	printf("Isi dari stack A saat ini :");
	prinTstack(A);
	printf("\n");
	printf("Isi dari stack A yang tidak kosong saat ini :");
	viewStack(A);
	printf("\n");
	printf("posisi dari top di stack A adalah : %d\n", top(A));
	printf("Nilai dari top pada Stack A adalah : %c\n",infotop(A));
	
	if(isEmptyStack(A)){
		printf("Stack A masih kosong \n");
	}else{
		printf("Stack A sudah berisi \n");
	}
	
	pop(&A,&X1);
	printf("nilai yang di KELUARKAN stack A : %c\n",X1);
	pushBabel1(&A,'A');
	printf("stack A setelah di push babel : ");
	viewStack(A);
	printf("\n");
	printf("\n");
	
	
	/*Stack B*/
	createStack(&B);
	push(&B,'W');
	push(&B,'A');
	push(&B,'T');
	push(&B,'A');
	push(&B,'S');
	push(&B,'H');
	push(&B,'I');
	push(&B,'W');
	push(&B,'A');
	push(&B,'W');
	
	printf("Isi dari stack B saat ini :");
	prinTstack(B);
	printf("\n");
	printf("Isi dari stack B yang tidak kosong saat ini : ");
	viewStack(B);
	printf("\n");
	printf("posisi dari top di stack B adalah : %d\n", top(B));
	printf("Nilai dari top pada Stack B adalah : %c\n",infotop(B));
	
	if(isFullStack(B)){
		printf("Stack B sudah penuh \n");
	}else{
		printf("Stack B masih punya tempat kosong");
	}
	
	pop(&B,&X2);
	printf("nilai yang di KELUARKAN stack B : %c\n",X2);
	
	pushBabel1(&B,'K');
	printf("stack B setelah di push babel : ");
	viewStack(B);
	printf("\n");
	printf("\n");
	
	
	
	printf("NOTE : nilai Top stack A menjadi A bukan N karena sudah di lakukan pop\n");
	printf("NOTE : nilai Top stack B menjadi K bukan W karena sudah di lakukan pop");
	printf("\n");
	
	
	
	/*Palindrom*/
	
	
	/*panjang string*/
	p = strlen(kata);
	createStack(&C);
	
	/*mencari nilai tengah kata*/
	div = floor(p/2); 
	
	/*true bila palindrom false bila tidak ( asumsi awal selalu true)*/
	boolean hasil;
	hasil = true;
	
	/*iterator*/
	for(j=0;j<div;j++){
		push(&C,kata[j]);
	}
	/*apabila nilai ganjil maka akan di skip sekali*/
	if(p%2 == 1){
		j++;
	}
	
	/*Mengecek nilai selanjutnya apakah sama dengan yang ada di top*/
	while(j<p){
		/*setiap kali melakukan iterasi di lakukan pop 
		untuk memindahkan posisi top*/
		pop(&C,&X3);
		/*bila ada karakter yang berbeda 
		maka iterasi berhenti */
		if(kata[j] != X3){
			hasil = false;
			break;
		}
		j++;
	}
	
	if(hasil){
		printf("\nmerupakan kata palindrom");
	}else{
		printf("\nbukan merupakan kata palindrom");
	}
	
	return 0;
}











