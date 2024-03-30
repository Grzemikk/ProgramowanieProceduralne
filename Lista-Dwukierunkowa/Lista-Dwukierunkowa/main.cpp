#include"list2.h"
#include"global.h"
#include<stdio.h>
#include<stdlib.h>




int main() {

	// Tworzenie nowej listy 
	LinkedList* list = LCreate();
	if( !list ) {
		perror( "Create Error" );
		return -100;
	}

	// dodawanie 4 elementów 
	LISTINFO* el1 = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
	if( !el1 ) {
		perror( "Allocation Error!" );
		return -1;
	}
	// ListItem* item1 = (ListItem*) calloc( 1, sizeof( ListItem ) );
	// int key1 = 37;
	el1->key = 37;
	int Insert1 = LInsertBefore( list, list->pFirst, el1->key );
	if( !Insert1 ) {
		perror( "Insert Error" );
		return -10;
	}



	LISTINFO* el2 = (LISTINFO*) calloc(1, sizeof(LISTINFO) );
	if( !el2 ) {
		perror( "Allocation Error!" );
		return -1;
	}
	el2->key = 21;
	int Insert2 = LInsertBefore( list, list->pFirst, el2->key );
	if( !Insert2 ) {
		perror( "Insert Error" );
		return -10;
	}


	
	LISTINFO* el3 = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
	if( !el3 ) {
		perror( "Allocation Error!" );
		return -1;
	}
	el3->key = 13;
	int Insert3 = LInsertBefore( list, list->pFirst, el3->key );
	if( !Insert3 ) {
		perror( "Insert Error" );
		return -10;
	}




	LISTINFO* el4 = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
	if( !el4 ) {
		perror( "Allocation Error!" );
		return -1;
	}
	el4->key = 4;
	int Insert4 = LInsertBefore( list, list->pFirst, el4->key );
	if( !Insert4 ) {
		perror( "Insert Error" );
		return -10;
	}
	




	// Wydruk listy po dodaniu 4 elementów 
	printf( "List with 4 elelemnts:\n" );
 	LPrintFromFirst( list, print );



	// Wypisanie od ty³u
	printf( "List written backwards:\n" );
	LPrintFromLast( list, print );




	// Dodanie elementu za 1 elementem 
	LISTINFO* el5 = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
	if( !el5 ) {
		perror( "Allocation Error!" );
		return -1;
	}
	el5->key = 100;
	int Insert5 = LInsertAfter( list, list->pFirst, el5->key );
	if( !Insert5 ) {
		perror( "Insert Error" );
		return -10;
	}

	printf( "List after adding element after first:\n" );
	LPrintFromFirst( list, print );




	// Usuwanie elementu za pierwszy elementem 
	int del = LDeleteAfter( list, list->pFirst, freeMem );
	if( !del ) {
		perror( "Delete Error" );
		return -3;
	}

	printf( "List after deleting element after first:\n" );
	LPrintFromFirst( list, print );




	// Usuwanie elementu przed ostatnim  elementem 
	int del2 = LDeleteBefore( list, list->pLast, freeMem );
	if( !del2 ) {
		perror( "Delete Error" );
		return -3;
	}

	printf( "List after deleting element before last:\n" );
	LPrintFromFirst( list, print );




	// dodanie elementu i wyszukanie go 
	LISTINFO* el6 = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
	if( !el6 ) {
		perror( "Allocation Error!" );
		return -1;
	}
	el6->key = 1000;
	int Insert6 = LInsertAfter( list, list->pFirst, el6->key );
	if( !Insert6 ) {
		perror( "Insert Error" );
		return -10;
	}


	printf( "List after adding element with key 1000:\n" );
	LPrintFromFirst( list, print );

	ListItem* wanted = LFind( list, el6, compare );
	if( !wanted ) {
		perror( "Item not found\n" );
	}
	else {
		printf( "Adress of wanted element: %d\n", wanted );
		printf( "Key: %d\n\n", wanted->data->key );
	}




// Czyszczenie listy 
//	printf( "Clearing list\n" );
//	LCLear( list, freeMem );

 // Usuwanie listy
	printf( "Removing list......\n\n" );
	LRemove( &list, freeMem );	

	if( !list ) {
		printf( "List removed correctly\n" );
	}



	return 0;
}



int compare( const void* A, const void* B ) {
	if( ( (LISTINFO*) A )->key == ( (LISTINFO*) B )->key ) return 1;
	else return 0;
}



void freeMem( const void* A ) {
	free( (LISTINFO*) A );
}



void print( const void* A ) {
	printf( "Key: %d \n", ( (LISTINFO*) A )->key );
}