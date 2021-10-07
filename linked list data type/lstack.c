/* Program   : lstack.c */
/* Deskripsi : file BODY modul stack berkait */
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 6-10-2021*/
/***********************************/
#ifndef lstack_c
#define lstack_c
#include "lstack.h"
#include <stdlib.h>

/*procedure alokasi(input/output P:address,input E:integer)
{I.S.: E terdefinisi}
{F.S.: P terdefinisi info(P) = P^.info = E, atau nil}
{proses: mengalokasi ruang memori untuk nilai E} */
void alokasi(address *P, int E)
{ //kamus lokal

  //algoritma
  *P = (address) malloc(sizeof(telms));
  if (*P != NIL ) 
  {
	  info(*P) = E;
	  down(*P) = NIL;
  }
}

/*procedure dealokasi(input/output P:address)
{I.S.: P terdefinisi }
{F.S.: P nil}
{proses: membebaskan ruang memori}*/
void dealokasi(address *P)
{ //kamus lokal 

  //algoritma 
    info(*P) = 0;
	down(*P) = NIL;
	*P = NIL;
	//free((*P));
}

/* function isEmptyLStack(S:lstack)-> boolean
{mengembalikan true jika stack kosong} */
boolean isEmptyLStack(lstack S){
	//kamus lokal 

 	//algoritma 
 	if(top(S) == NIL){
 		return true;
	 }else{
	 	return false;
	 }
	 	
}

/*procedure createLStack( output S:lstack)
{I.S.: -}
{F.s.: S terdefinisi}
{proses: membentuk stack kosong}*/
void createLStack(lstack *S){
	//kamus lokal 

 	//algoritma 
 		top(*S) = NIL;
 	
}

/*procedure pushL( input/output S:lstack, input E:integer)
{I.S.: E terdefinisi }
{F.S.: S.top^.info = E atau S tetap}
{proses: memasukkan E sebagai top(S) } */
void pushL(lstack *S, int E){
	//kamus lokal 
	address P;

 	//algoritma 
 	alokasi(&P,E);
 	if(P != NIL){
 		down(P) = top(*S);
 		top(*S) = P;
	 }
 	
}

/*procedure popL( input/output S:lstack, output X:integer)
{proses menghapus top(S), nilainya disalin di X}
{asumsi, jika stack kosong, maka X=-999} */
void popL(lstack *S, int *E){
	//kamus lokal 
	address P;

 	//algoritma 
 	if(isEmptyLStack(*S)){
 		*E = -999;
	 }else{
	 	P = top(*S);
	 	(*E) = infotop(*S);
	 	top(*S) = down(top(*S));
	 	down(P) = NIL;
	 	dealokasi(&P);
	 }
}

/*procedure viewLStack( input S:lstack)	 
{I.S.: s terdefinisi }
{F.S.: -}
{proses: menampilkan isi stack ke layar, pesan khusus jika kosong} */
void viewLStack(lstack S){
	/*Kamus Lokal*/
	address A;
	
	/*Algortima*/
	if(!isEmptyLStack(S)){
		A = top(S);
		while(down(A) != NIL){
			printf("%d ",info(A));
			A = down(A);
		}
		printf("%d ",info(A));
	}
	
}

/*function tinggiL(S:lstack) -> integer 
{menghitung panjang/tinggi/kedalaman tumpukan} */
int tinggiL(lstack S){
	//kamus lokal 
	address A;
	int size;

 	//algoritma 
 	size = 0;
 	A = top(S);
 		while(A!=NIL){
 			size++;
 			A = down(A);
		 }
	return size;
}


#endif





