/***********************************/
/* Program   : tqueue2.c */
/* Deskripsi : realisasi dari file header tqeueu.h */
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 30-9-2021*/
/***********************************/

#ifndef tqueue2_c
#define tqueue2_c
#include <stdio.h>
#include "boolean.h"
#include "tqueue2.h"

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/ 
void createQueue2(tqueue2 *Q){
	/*Kamus Lokal*/
	int i; /*iterartor*/
	
	/*algortima*/
	(*Q).head = 0;
	(*Q).tail = 0;
	for(int i=1;i<=5;i++){
		(*Q).wadah[i] = '@';
	}
}

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(Q.tail == 0 && Q.head == 0){
		return true;
	}else{
		return false;
	}
}

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(Q.tail == 5 && Q.head == 1){
		return true;
	}else{
		return false;
	}
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(sizeQueue2(Q) == 1){
		return true;
	}else{
		return false;
	}
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue Q);
int Head2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	return Q.head;
}

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue Q);
int Tail2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	return Q.tail;
}


/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if (!isEmptyQueue2(Q)){
		return Q.wadah[Q.head];
	}else{
		return '@';
	}
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if (!isEmptyQueue2(Q)){
		return Q.wadah[Q.tail];
	}else{
		return '@';
	}
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
	/*Kamus Lokal*/
	
	/*Algortima*/
	if(isEmptyQueue2(Q)){
		return 0;
	}else{
		return Q.tail-Q.head+1;
	}
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
	/*Kamus Lokal*/
	int i;/*iterator*/
	
	/*Algortima*/
	for(int i=1;i<=5;i++){
		printf("%c ",Q.wadah[i]);
	}
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
	/*Kamus Lokal*/
	int i; /*iterartor*/
	
	/*algortima*/
	if(!isEmptyQueue2(Q)){
		for(int i=Q.head;i<=Q.tail;i++){
		printf("%c ",Q.wadah[i]);
		}
	}
}

/*Function IsTailStop2(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop2(tqueue2 Q){
	/*Kamus Lokal*/
	
	
	/*algortima*/
	if(!isFullQueue2(Q) && Q.tail == 5){
		return true;
	}else{
		return false;
	}
}

/*Procedure ResetHead2(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead2(tqueue2 *Q){
	/*Kamus Lokal*/
	int i,j; /*iterator*/
	int temp;
	
	/*Integer*/
	if(isTailStop2(*Q)){
		temp = 1;
		for(i=(*Q).head;i<=(*Q).tail;i++){
			(*Q).wadah[temp] = (*Q).wadah[i];
			temp++;
		}
		for(j=(*Q).tail;j<=5;j++){
			(*Q).wadah[j] = '@';
		}
		(*Q).head = 1;
		(*Q).tail = temp-1;
	}
	
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
	/*Kamus Lokal*/
	int i,j; /*iterator*/
	int temp;
	
	/*Algortima*/
	if(!isTailStop2(*Q)){
		(*Q).tail++;
		(*Q).wadah[(*Q).tail] = E;
		if((*Q).tail == 1){
			(*Q).head = 1;
		}
	}else{
		if(!isFullQueue2((*Q))){
			temp = 1;
			for(i=(*Q).head;i<=(*Q).tail;i++){
				(*Q).wadah[temp] = (*Q).wadah[i];
				temp++;
			}
			for(j=(*Q).tail;j<=5;j++){
				(*Q).wadah[j] = '@';
			}
			(*Q).head = 1;	
			(*Q).wadah[(*Q).tail] = E;
			(*Q).tail = temp;
			
		}
	}
}
	
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
	/*Kamus Lokal*/
	int i;/*iterator*/
	
	/*Algortima*/
	if(!isEmptyQueue2(*Q)){
		*E = (*Q).wadah[(*Q).head];
		(*Q).wadah[(*Q).head] = '@';
		if((*Q).head!=10){
			(*Q).head++;
		}else{
			(*Q).head = 0;
		}
	}else{
		*E = '@';
	}
	
}
	

#endif
