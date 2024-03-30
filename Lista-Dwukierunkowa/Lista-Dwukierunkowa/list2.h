#pragma once
#include"global.h"


// LISTA DWUKIERUNKOWA
//--------------------------

/* Lista elepment�w po��czonych w obydwu kierunkach. Obydwa po��czenia rozpoczynaj�
sie od glowy (pFirst, pLast) zawieraj�cej odsy�acze do obu koncow listy

Zaimplementowac modu� listy dwukierunkowej przechowuj�cej dowolna informacj�
(element listy zawiera wskaznik do informacji)
zawieraj�cej metody:
- kreowanie listy (zwraca wskaznik na glowe)  LCreate()
- wstawianie po wskazanym elemencie listy     LInsertAfter()
- wstawianie przed wskazanym elementem listy  LInsertBefore()
- usuwanie po wskazanym elemencie listy       LDeleteAfter()
- usuwanie przed wskazanym elementem listy    LDeleteBefore()
- wydruk listy od pFirst                      LPrintFromFirst()
- wydruk listy od pLast                       LPrintFromLast()
- wyszukiwanie informacji w liscie            LFind()
- czyszcenie listy                            LCLear()
- usuwanie listy                              LRemove()
*/


typedef struct ListItem {
	LISTINFO* data;
	ListItem* pPrev;
	ListItem* pNext;
}ListItem;


typedef struct LinkedList {
	struct ListItem* pFirst;
	struct ListItem* pLast;
}LinkedList;


LinkedList* LCreate();
int LInsertAfter( LinkedList* list, ListItem* item, int key );
int LInsertBefore( LinkedList* list, ListItem* item, int key );
int LDeleteAfter( LinkedList* list, ListItem* item, void( __cdecl freeMem )( const void* ) );
int LDeleteBefore( LinkedList* list, ListItem* item, void( __cdecl freeMem )( const void* ) );
void LPrintFromFirst( LinkedList* list, void( __cdecl* print )( const void* ) );
void LPrintFromLast( LinkedList* list, void( __cdecl* print )( const void* ) );
ListItem* LFind( LinkedList* list, LISTINFO* data, int( __cdecl* compareFunc )( const void*, const void* ) );
void LCLear( LinkedList* list, void( __cdecl* freeMem )( const void* ) );
void LRemove( LinkedList** list, void( __cdecl* freeMem )( const void* ) );


