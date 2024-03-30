#pragma once 

#include"global.h"

typedef struct tagListItem {
  LISTINFO* pInfo;          // wskaünik do zdefiniowanej stga≥em preprocesora
  tagListItem* pNext;       // wskaünik do nastÍpneo elementu listy 
} ListItem;


ListItem* CreateList(); //empty elem on top (GUARD)
int       Insert( ListItem* pAfter, LISTINFO* pInfo/*wsk do inf - pInfo */ ); // insert po elemencie wskazywanym przez pAfter
LISTINFO* Remove( ListItem* pAfter );      // usun element po elemencie wsk przez pAfter
LISTINFO* Front( ListItem* pList );        // zwraca wsk do informacji pierwszego (jak top() w stosie)
int       IsEmpty( ListItem* pList );     // 1 pusta,  0 -nie pusta  - nie uzywac if!
void      ClearList( ListItem* pList, void( __cdecl *freeMem )( const void* )/* pointer to the function of void type with one parameter const void*  */ );
void      RemoveList( ListItem** pList, void( __cdecl *freeMem )( const void* ) /* pointer to the function of void type with one parameter const void*  */ );  // after removing, set list as NULL
void      SortList( ListItem* pList, int( __cdecl *compare )( const void*, const void* ) );  /* pointer to the function with two parameters const void* and returned int value */
ListItem* Find( ListItem* pList, const void*  pItem/*ptr to info to find - const void* */, ListItem** pPrev/*wsk na poprzednigo do znalezionego*/,
  int( __cdecl *compare )( const void*, const void* )/* pointer to the function with two parameters const void* and returned int value */ );



