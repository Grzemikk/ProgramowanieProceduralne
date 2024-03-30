/*Drzewo dok�adnie wywa�one

Drzewo zawieraj�ce klucz( nKey ) typu ca�kowitego o raz dwa wska�niki na lewe i prawe poddrzewo : pLeft i pRight

Zaimplementowa� drzewo dok�adnie wywa�one tj takie dla kt�rego w ka�dym jego wierzcho�ku
ilo�� element�w jego lewego i prawego poddrzewa r�ni si� co najwy�ej o jeden

Zbudowa� takie drzewo z 20 losowymi elementami i zaprezentowa� na ekranie w pionie iod korzenia u g�ry
( wypisa� tylko klucze z odpowiednimi wcieciami ) algorytm budowania takiego drzewa w With "algorytmy + struktury danych = programy"
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"TreeW.h"

#define SIZE 20



int main() {
	
	Tree* T = CreateTree( SIZE );
	if( !T ) {
		perror( "Create Error" );
		return -1;
	}
	

	printf( "Drzewo poziomo: \n\n\n" );
	PrintTree( T, 0 );
	printf( "\n\n\n" );

	printf( "Drzewo pionowo: \n\n\n" );
	PrintTree2( T, 64 );
	printf( "\n\n\n" );


	FreeTree( &T );
	printf( "Czyszczenie Drzewa.....\n\n" );
	if( !T ) {
		printf( "Drzewo wyczyszczone poprawnie\n\n" );
	}


	return 0;
}