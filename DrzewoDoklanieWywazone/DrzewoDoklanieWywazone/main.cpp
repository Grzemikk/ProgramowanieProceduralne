/*Drzewo dok³adnie wywa¿one

Drzewo zawieraj¹ce klucz( nKey ) typu ca³kowitego o raz dwa wskaŸniki na lewe i prawe poddrzewo : pLeft i pRight

Zaimplementowaæ drzewo dok³adnie wywa¿one tj takie dla którego w ka¿dym jego wierzcho³ku
iloœæ elementów jego lewego i prawego poddrzewa ró¿ni siê co najwy¿ej o jeden

Zbudowaæ takie drzewo z 20 losowymi elementami i zaprezentowaæ na ekranie w pionie iod korzenia u góry
( wypisaæ tylko klucze z odpowiednimi wcieciami ) algorytm budowania takiego drzewa w With "algorytmy + struktury danych = programy"
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