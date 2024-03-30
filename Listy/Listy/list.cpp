#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>



// Sprawdza, czy lista jest pusta
int IsEmpty( ListItem* pList ) {
	// if( pList == NULL ) return 1;
	// else if( !( pList->pNext ) ) return 1;
	// return 0;
	return !pList || !pList->pNext;
}

// Tworzy now� list�
ListItem* CreateList() {
	return (ListItem*) calloc( 1, sizeof( ListItem ) );
}

// Wstawia nowy element do listy po okre�lonym elemencie
int Insert( ListItem* pAfter, LISTINFO* pInfo ) {
	if( !pAfter ) return 0;
	ListItem* New = (ListItem*) calloc( 1, sizeof( ListItem ) );
	if( !New ) return 0;
	New->pInfo = pInfo;
	New->pNext = pAfter->pNext;
	pAfter->pNext = New;
	return 1;
}

// Usuwa element z listy po okre�lonym elemencie i zwraca wska�nik na kolejny element
LISTINFO* Remove( ListItem* pAfter ) {
	if( IsEmpty( pAfter ) ) return NULL;
	ListItem* p = pAfter->pNext;  // usuwany 
	ListInfo* next = p->pInfo;    // kolejny
	pAfter->pNext = p->pNext;     // podstawiamy 
	free( p );
	return next;
}

// Zwraca wska�nik na pierwszy element listy
LISTINFO* Front( ListItem* pList ) {
	return ( !IsEmpty( pList ) ) ? pList->pNext->pInfo : NULL;
}

// Czy�ci list�, zwalniaj�c pami�� za pomoc� funkcji freeMem
void ClearList( ListItem* pList, void( __cdecl *freeMem )( const void* ) ) {
	if( !freeMem || !pList ) {
		perror( "freeMem function not found or list does not exist!\n" );
		return;
	}
	while( !IsEmpty( pList ) && freeMem != NULL )
	{
		freeMem( Remove( pList ) );
	}
}

// Usuwa list� i zwalnia jej pami�� za pomoc� funkcji freeMem
void RemoveList( ListItem** pList, void( __cdecl *freeMem )( const void* ) ) {
	if( !pList || !*pList ) {
		perror( "List does not exist !\n" );
		return;
	}
	ClearList( *pList, freeMem );
	free( *pList );
	*pList = NULL;
}

// Sortuje list� za pomoc� funkcji compare
void SortList( ListItem* pList, int( __cdecl *compare )( const void*, const void* ) ) {
	if( !compare ) {
		perror( "compare function not found!\n" );
		return;
	}
	ListItem* pFirst = pList;
	while( !IsEmpty( pFirst ) ) {
		ListItem* pMin = pFirst;
		ListItem* pCurr = pFirst->pNext;
		while( !IsEmpty( pCurr ) ) {
			if( compare( pMin->pNext->pInfo, pCurr->pNext->pInfo ) == 1 ) pMin = pCurr;
			pCurr = pCurr->pNext;
		}
		if( pMin != pFirst ) {
			// nast�puje zamiana miejsc mi�dzy tym elementem a pierwszym elementem listy
			// Przechowuje wska�nik na nast�pny element po pCurr
			pCurr = pMin->pNext->pNext;
			// Aktualizuje wska�nik nast�pnego elementu po pMin, aby wskazywa� na element po pFirst
			pMin->pNext->pNext = pFirst->pNext;
			// Aktualizuje wska�nik nast�pnego elementu po pFirst, aby wskazywa� na element po pMin
			pFirst->pNext = pMin->pNext;
			// Przywraca poprawne po��czenie nast�pnego elementu po pMin z elementem po nim
			pMin->pNext = pCurr;
		}
		pFirst = pFirst->pNext;
	}
}

// Znajduje element w li�cie na podstawie warto�ci pInfo za pomoc� funkcji compare
ListItem* Find( ListItem* pList, const void* pInfo, ListItem** pPrev, int( __cdecl *compare )( const void*, const void* ) ) {
	if( !compare || !pPrev ) return NULL;

	*pPrev = pList;
	while( !IsEmpty( *pPrev ) ) {
		if( compare( pInfo, ( *pPrev )->pNext->pInfo ) == 0 ) return ( *pPrev )->pNext;
		*pPrev = ( *pPrev )->pNext;
	}
	return *pPrev = NULL;
}
