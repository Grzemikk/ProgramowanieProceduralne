#include"list2.h"
#include<stdio.h>
#include<stdlib.h>





LinkedList* LCreate() {
	LinkedList* newList = (LinkedList*) calloc( 1, sizeof( LinkedList ) );
	if( !newList ) {
		return NULL;
	}
	newList->pFirst = NULL;
	newList->pLast = NULL;


	return newList;
}



int LInsertAfter( LinkedList* list, ListItem* item, int key ) {
	if( !list || !key ) {
		perror( "Invalid input\n" );
		return 0;
	}

	if( !list->pFirst && !list->pLast ) {
		ListItem* newI = (ListItem*) calloc( 1, sizeof( ListItem ) );
		LISTINFO* data = (LISTINFO*) calloc( 1, sizeof( ListItem ) );

		data->key = key;
		newI->data = data;
		list->pFirst = newI;
		list->pLast = newI;
	}

	ListItem* newItem = (ListItem*) calloc( 1, sizeof( ListItem ) );
	if( !newItem ) {
		return 0;
	}
	LISTINFO* dat = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
	dat->key = key;
	newItem->data = dat;


	if( item ) {
		newItem->pNext = item->pNext;
		newItem->pPrev = item;
		if( !( item->pNext ) ) {
			item->pNext->pPrev = newItem;
		}
		item->pNext = newItem;
		if( list->pLast == item ) {
			list->pLast = newItem;
		}
	 }
	else {
		newItem->pNext = list->pFirst;
		newItem->pPrev = NULL;
		if( list->pFirst != NULL ) {
			list->pFirst->pPrev = newItem;
		}
		list->pFirst = newItem;
		if( list->pLast == NULL ) {
			list->pLast = newItem;
		}
	}
	return 1;
}



int LInsertBefore( LinkedList* list, ListItem* item, int key ) {
	if( !list || !key ) {
		perror( "Invalid input\n" );
		return 0;
	}

	if( !list->pFirst && !list->pLast ) {
		ListItem* newI = (ListItem*) calloc( 1, sizeof( ListItem ) );
		LISTINFO* data = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
		data->key = key;
		newI->data = data;


		list->pFirst = newI;
		list->pLast = newI;
	}


	ListItem* newItem = (ListItem*) calloc( 1, sizeof( ListItem ) );
	if( !newItem ) {
		return 0;
	}
	LISTINFO* dat = (LISTINFO*) calloc( 1, sizeof( LISTINFO ) );
	dat->key = key;
	newItem->data = dat;



	// newItem->data->key = key;

	if( item ) {
		newItem->pNext = item;
		newItem->pPrev = item->pPrev;
		if( item->pPrev ) {
			item->pPrev->pNext = newItem;
		}
		item->pPrev = newItem;
		if( list->pFirst == item ) {
			list->pFirst = newItem;
		}
		else {
			newItem->pNext = list->pFirst;
			newItem->pPrev = NULL;
			if( list->pFirst ) {
				list->pFirst->pPrev = newItem;
			}
			list->pFirst = newItem;
			if( list->pLast == NULL ) {
				list->pLast = newItem;
			}
		}
	}
	return 1;
}



int LDeleteAfter( LinkedList* list, ListItem* item, void( __cdecl freeMem )( const void* ) ) {
	if( !list || !item || !( item->pNext ) ) {
		perror( "Invalid input\n" );
		return 0;
	}

	ListItem* del = item->pNext;
	item->pNext = del->pNext;

	if( del->pNext ) {
		del->pNext->pPrev = item;
	}

	if( list->pLast == del ) {
		list->pLast = item;
	}

	freeMem( del->data );
	free( del );
	return 1;
}



int LDeleteBefore( LinkedList* list, ListItem* item, void( __cdecl freeMem )( const void* ) ) {
	if( !list || !item || !( item->pPrev ) ) {
		perror( "Invalid input\n" );
		return 0;
	}

	ListItem* del = item->pPrev;
	item->pPrev = del->pPrev;

	if( del->pPrev ) {
		del->pPrev->pNext = item;
	}

	if( list->pFirst == del ) {
		list->pFirst = item;
	}


	freeMem( del->data );
	free( del );
	return 1;
}




void LPrintFromFirst( LinkedList* list, void( __cdecl* print )( const void* ) ) {
	if( !list ) return;

	ListItem* currentItem = list->pFirst;
	int i = 1;
	while( currentItem ) {
		printf( "\t%d. ", i );
		print( currentItem->data );
		currentItem = currentItem->pNext;
		i++;
	}
	printf( "\n\n" );
}




void LPrintFromLast( LinkedList* list, void( __cdecl* print )( const void* ) ) {
	if( !list ) return;

	ListItem* currentItem = list->pLast;
	int i = 1;
	while( currentItem ) {
		printf( "\t%d. ", i );
		print( currentItem->data );
		currentItem = currentItem->pPrev;
		i++;
	}
	printf( "\n\n" );
}




ListItem* LFind( LinkedList* list, LISTINFO* data, int( __cdecl* compareFunc )( const void*, const void* ) ) {
	if( !list ) return NULL;

	ListItem* currentItem = list->pFirst;

	while( currentItem ) {
		if( compare( currentItem->data, data ) ) {
			return currentItem;
		}
		currentItem = currentItem->pNext;
	}

	return  NULL;
}




void LCLear( LinkedList* list, void( __cdecl* freeMem )( const void* ) ) {
	if( !list ) return;

	ListItem* currentItem = list->pFirst;

	while( currentItem ) {
		ListItem* temp = currentItem;
		currentItem = temp->pNext;
		if( temp->data ) {
			freeMem( temp->data );
		}
		free( temp );
	}
}





void LRemove( LinkedList** list, void( __cdecl* freeMem )( const void* ) ) {
	if( !*list ) return;

	LCLear( *list, freeMem );
	(*list)->pFirst = NULL;
	(*list)->pLast = NULL;
	*list = NULL;
	free( *list );
}
