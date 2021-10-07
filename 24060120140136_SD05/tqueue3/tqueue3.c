/***********************************/
/* Program   : tqueue3.c */
/* Deskripsi : realisasi dari file header tqueue3.h */
/* NIM/Nama  : 2406012014013/Benhard Simanullang*/
/* Tanggal   : 30-9-2021*/
/***********************************/#ifndef tqueue3_c
#define tqueue3_c 
#include "boolean.h"
#include <stdio.h>
#include "tqueue3.h"


/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/ 
void createQueue3(tqueue3 *Q){
	/*Kamus Lokal*/
	int i;/*iterartor*/
	
	
	/*Algoritma*/
	(*Q).head = 0;
	(*Q).tail = 0;
	for(i=1;i<=5;i++){
		(*Q).wadah[i] = '@';
	}
}

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if(Q.tail == 0 && Q.head == 0){
		return true;
	}else{
		return false;
	}
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if((Q.tail % 10)+1 == Q.head){
		return true;
	}else{
		return false;
	}
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if(!isEmptyQueue3(Q) && Q.head == Q.tail){
		return true;
	}else{
		return false;
	}
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	return Q.head;
	
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	return Q.tail;
	
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if (!isEmptyQueue3(Q)){
		return Q.wadah[Q.head];
	}else{
		return '@';
	}
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if (!isEmptyQueue3(Q)){
		return Q.wadah[Q.tail];
	}else{
		return '@';
	}
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(isEmptyQueue3(Q)){
		return 0;
	}else{
		return ((10-Q.head+Q.tail)%10) + 1;
	}
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar}*/
void printQueue3(tqueue3 Q){
	/*Kamus Lokal*/
	int i;/*iterator*/
	
	/*Algortima*/
	for(i=1;i<=5;i++){
		printf("%c ", Q.wadah[i]);
	}
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
	/*Kamus Lokal*/
	int i;/*iterator*/
	
	/*Algortima*/
	for(i = Q.head ;i<=Q.head+sizeQueue3(Q)-1;i++){
		printf("%c ",Q.wadah[(i-1)%5 + 1]);
	}
	
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E){
	/*Kamus Lokal*/
	
	
	/*Algortima*/
	if(!isFullQueue3(*Q)){
		if(isEmptyQueue3((*Q))){
			(*Q).head = 1;
		}
		(*Q).tail = ((*Q).tail+1)%10;
		(*Q).wadah[(*Q).tail] = E;
	}
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
	/*Kamus Lokal*/
	
	
	/*Algortima*/
	if(!isEmptyQueue3(*Q)){
		*E = (*Q).wadah[(*Q).head];
		if((*Q).head = (*Q).tail){
			(*Q).head = 0;
			(*Q).tail = 0;
		}else{
			(*Q).head = (*Q).head % 10 + 1;
		}
	}else{
		*E = '@';
	}
	
}



#endif
