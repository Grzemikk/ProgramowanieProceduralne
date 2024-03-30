
// operacje na liscie ktore przechowuja dane dowolnego typu 

// sortowanie oraz wyszukiwanie na liscie
// funkcja porownujaca, porownuje 2 elementy informacji uzytkownika

#include <stdio.h>
#include "list.h"
#include<time.h>
#include <stdlib.h>



#define MAX 50
#define SIZE 20
#define IX 9
#define KEY1 2000
#define KEY2 3000



int compare( const void* a, const void* b );
void freeMem( const void* a );
void Print( ListItem* pList );
ListInfo* Create( int key, int ix );

int main()
{
	ListItem* pList = CreateList();
	if( !IsEmpty( pList ) ) {
		perror( "CreateList Error!\n" );
		return -1;
	}
	srand( (unsigned int) time( NULL ) );  // start rand ( time zmienia ziarna, przy kazdym wykonaniu inna liczba )

	// 20 elementów z kluczami losowymi( < 50 ) ( nKey ) a do pierwszego elementu dynamicznej tablicy 
	//	dwuelementowej wstawiaæ indeks pêtli( dla indeksu 9 wstawiæ klucz2000 )

	for( int i = 0; i < SIZE; i++ ) {
		int key = 0;
		int ix = i;
		if( i == IX ) key = KEY1;
		else
			key = rand() % MAX;

		LISTINFO* pInfo = Create( key, ix );
		if( !pInfo ) {
			perror( "Create Error2!\n" );
			return -2;
		}

		if( !( Insert( pList, pInfo ) ) ) {
			perror( "Insert Error!\n" );
			return -3;
		}
	}


	printf( "List:\n" );
	Print( pList );

	SortList( pList, compare );   // Sortowanie listy
	printf( "\nSorted list:\n" );
	Print( pList );

	ListItem* pPrev = NULL;
	LISTINFO* MM = Create( KEY1, IX );
	if( !MM )
	{
		perror( "MM Create Error!\n" );
		return -4;
	}
	// wyszukiwanie elementu z kluczem 2000


	ListItem* Found = Find( pList, MM, &pPrev, compare );

	if( Found && Found->pInfo )
	{
		printf( "%d\n", Found->pInfo->nKey );
		if( pPrev->pInfo )
			printf( "%d\n", pPrev->pInfo->nKey );
	}
	else perror( "pPrev->pInfo is NULL\n" );

	freeMem( MM );


	LISTINFO* pMM = Create( KEY2, 10 );
	if( !Insert( pPrev, pMM ) ) {           // wstawianie elementu z kluczem 3000 przed element z kluczem 2000

		perror( "Insert 3000Item Error!\n" );
		freeMem( pMM );
		return -6;
	}


	printf( "List with added Item\n" );
	Print( pList );

	LISTINFO* Rem = Remove( pPrev->pNext );         // usuwanie elementu z kluczem 2000
	if( !Rem ) {
		perror( "MM Remove Error!\n" );
		return -7;
	}
	printf( "List after removing 2000Item\n" );
	Print( pList );
	freeMem( Rem );
	ClearList( pList, freeMem );


	LISTINFO* I1 = Create( 546, 741 );    // tworzenie 2 nowych elementów 
	if( !I1 ) {
		perror( "I1 Create  Error!\n" );
		return -8;
	}

	if( !Insert( pList, I1 ) ) {        //  dodawanie pierwszego elementu
		perror( "Insert I1 Error\n" );
		freeMem( I1 );
		return -9;
	}

	LISTINFO* I2 = Create( 718, 453 );
	if( !I2 ) {
		perror( "I2 Create Error!\n" );
		return -10;
	}

	//Insert( pList, I2 );                 // dodawanie drugiego elementu 
	if( !Insert( pList, I2 ) ) {
		perror( "Insert I2 Error\n" );
		freeMem( I2 );
		return -11;
	}


	printf( "List with added 2 new items\n" );   // wypisywanie koñcowej listy
	Print( pList );

	RemoveList( &pList, freeMem );    // usuwanie listy 
	if( !pList ) printf( "List removed correctly\n" );
	Print( pList );

	return 0;

}






int compare( const void* a, const void* b ) {             // Porównuje wartoœci kluczy dwóch elementów listy
	if( ( (LISTINFO*) a )->nKey < ( (LISTINFO*) b )->nKey ) return -1;
	if( ( (LISTINFO*) a )->nKey > ( (LISTINFO*) b )->nKey ) return 1;
	return 0;
}


void freeMem( const void* a ) {  // Zwolnienie pamiêci zajmowanej przez element listy
	free( ( (LISTINFO*) a )->p );
	free( (LISTINFO*) a );
}


void Print( ListItem* pList ) {    // Wyœwietla elementy listy.																	
	if( IsEmpty( pList ) ) return;   // Przechodzi przez listê, wyœwietla klucz i p
	int i = 0;
	while( !IsEmpty( pList ) ) {
		i++;
		printf( "Key %d = %d\n", pList->pNext->pInfo->p[ 0 ], pList->pNext->pInfo->nKey );
		pList = pList->pNext;
		// printf( "\a" );
		// Sleep( 400 );
	}
}


LISTINFO* Create( int key, int ix ) {                               // Tworzy nowy element listy.               
	LISTINFO* P = (LISTINFO*) calloc( 1, sizeof( ListItem ) );         // Tworzy strukturê LISTINFO i alokuje pamiêæ na tablicê p
	if( !P ) return NULL;                                             // Ustawia wartoœæ klucza i p
	P->p = (int*) calloc( 2, sizeof( ListItem ) );                   // Zwraca wskaŸnik na utworzony element lub NULL w przypadku niepowodzenia
	if( !( P->p ) ) return NULL;
	P->nKey = key;
	P->p[ 0 ] = ix;
	return P;
}



