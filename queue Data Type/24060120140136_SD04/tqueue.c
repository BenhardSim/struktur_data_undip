/* Program   : tqueue.c */
/* Deskripsi : Realisasi fungsi dan procedure dari file header tqueue.h */
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 21 september 2021*/
/***********************************/
#ifndef tqueue_C
#define tqueue_C
#include <stdio.h>
#include "boolean.h"
#include "tqueue.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan '@' }*/ 
void createQueue(tqueue *Q){
	/*Kamus Lokal*/
	int i; /*iterartor*/
	
	/*algortima*/
	(*Q).head = 0;
	(*Q).tail = 0;
	for(int i=1;i<=5;i++){
		(*Q).wadah[i] = '@';
	}
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue Q);
int Head(tqueue Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	return Q.head;
}

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue Q);
int Tail(tqueue Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	return Q.tail;
}


/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead(tqueue Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if (!isEmptyQueue(Q)){
		return Q.wadah[Q.head];
	}else{
		return '@';
	}
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail(tqueue Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if (!isEmptyQueue(Q)){
		return Q.wadah[Q.tail];
	}else{
		return '@';
	}
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(isEmptyQueue(Q)){
		return 0;
	}else{
		return Q.tail-Q.head+1;
	}
	
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
	/*Kamus Lokal*/
	int i; /*iterartor*/
	
	/*algortima*/
	for(int i=1;i<=5;i++){
		printf("%c ",Q.wadah[i]);
	}
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi, ke layar}*/
void viewQueue(tqueue Q){
	/*Kamus Lokal*/
	int i; /*iterartor*/
	
	/*algortima*/
	if(!isEmptyQueue(Q)){
		for(int i=Q.head;i<=Q.tail;i++){
		printf("%c ",Q.wadah[i]);
		}
	}

}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
	/*Kamus Lokal*/
	
	/*algortima*/
	if(Q.tail == 0 && Q.head == 0){
		return true;
	}else{
		return false;
	}
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
	/*Kamus Lokal*/
	
	/*algortima*/
	if(Q.tail == 5 && Q.head == 1){
		return true;
	}else{
		return false;
	}
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E){
	/*Kamus Lokal*/
	
	/*algortima*/
	if(!isFullQueue(*Q)){
		(*Q).tail++;
		(*Q).wadah[(*Q).tail] = E;
		if((*Q).tail == 1){
			(*Q).head = 1;
		}
	}
}

/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead(Q) atau E=' ' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E){
	/*Kamus Lokal*/
	int i; /*iterartor*/
	
	/*algortima*/
	if(!isEmptyQueue(*Q)){
		(*E) = (*Q).wadah[(*Q).head];
		/*menggeser nilai*/
		for(i=(*Q).head;i<=(*Q).tail;i++){
			(*Q).wadah[i] = (*Q).wadah[i+1];
		}
		(*Q).wadah[(*Q).tail+1] = '@';
		(*Q).tail--;
		if((*Q).tail == 0){
			(*Q).head = 0;
		}
	}else{
		(*E) = '@';
	}
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
	/*Kamus Lokal*/
	
	/*algortima*/
	if(sizeQueue(Q) == 1){
		return true;
	}else{
		return false;
	}
}

/*tambahan, dikerjakan bila luang */


/*function maxlength(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int maxlength(tqueue Q1, tqueue Q2){
	/*Kamus Lokal*/
	
	/*algortima*/
	if(sizeQueue(Q1) > sizeQueue(Q2)){
		return sizeQueue(Q1);
	}else{
		return sizeQueue(Q2);
	}
}

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char E){
	/*Kamus Lokal*/
	
	/*algortima*/
	if(sizeQueue(*Q1) > sizeQueue(*Q2)){
		enqueue(Q2,E);
	}else if(sizeQueue(*Q1) < sizeQueue(*Q2)){
		enqueue(Q1,E);
	}
}

/*procedure deQueue2( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2 atau E=' ' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *E){
	/*Kamus Lokal*/
	
	/*algortima*/
	if(sizeQueue(*Q1) > sizeQueue(*Q2)){
		dequeue(Q1,E);
	}else if(sizeQueue(*Q1) < sizeQueue(*Q2)){
		dequeue(Q2,E);
	}
}



























#endif
