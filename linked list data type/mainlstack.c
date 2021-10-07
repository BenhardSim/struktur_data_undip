/* Program   : mainlstack.c */
/* Deskripsi : file DRIVER modul stack berkait */
/* NIM/Nama  : 24060120140136/Benhard Simanullang*/
/* Tanggal   : 6-10-2021*/
/***********************************/
#include <stdio.h>
#include "lstack.h"

int main()
{ //KAMUS----------------------------
    lstack LS;  /*variabel parameter aktual linked Stack */
    address A,B; /*variabel parameter aktual address */
	int E;
	
  //ALGORITMA------------------------
  	/*mengalokasi adress A dengan info 3*/
    alokasi(&A,3);
    alokasi(&B,4);
    (*A).down = B;
    printf("Nilai info dari A adalah = %d",info(A));
    printf("\nNilai dari stack di bawah top adalah : %d",info(down(A)));
    dealokasi(&A);
    
    
    createLStack(&LS);
    if(isEmptyLStack(LS)){
    	printf("\nlstack kosong");
	}else{
		printf("\nlstack terisi");
	}
	
	pushL(&LS,3);
	pushL(&LS,4);
	pushL(&LS,5);  
	printf("\nIsi dari lstack adalah : ");
	viewLStack(LS);
	printf("\nNilai Top dari lstack : %d",infotop(LS));
	printf("\nAddres dari Top : %d",top(LS));
	
	popL(&LS,&E);  
	printf("\nNilai yang dikeluarkan = %d" ,E);
	printf("\nIsi dari lstack adalah : ");
	viewLStack(LS);
	printf("\npanjang dari lstack = %d" , tinggiL(LS));
    
    return 0;
}
