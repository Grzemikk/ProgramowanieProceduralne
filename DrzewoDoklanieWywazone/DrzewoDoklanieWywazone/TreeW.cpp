#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"TreeW.h"


Tree* CreateTree( int size ) {
	if( !size ) {
		return 0;
	}
	int L = size / 2;  
	int R = size - L - 1;

	int key = ( rand() % 10 ) + 1;
	Tree* newNode = (Tree*) calloc( 1, sizeof( Tree ) );

	newNode->nKey = key;
	newNode->pLeft = CreateTree( L );
	newNode->pRight = CreateTree( R );

	return newNode;
}




void PrintTree( Tree* node, int space ) {
	if( node == NULL ) {
		return;
	}

	space += 4;


	PrintTree( node->pRight, space );

	for( int i = 0; i < space; i++ ) {
		printf( " " );
	}

	printf( "%d\n", node->nKey );

	PrintTree( node->pLeft, space );
}




void Space( int space ) {
	for( int i = 0; i < space; i++ ) {
		printf( " " );
	}
}



void PrintTree2( Tree* node, int space ) {
	if( node == NULL ) {
		return;
	}
	 


	Space( space );
	printf( "%d\n\n\n", node->nKey );
	Space( space * 3 / 4 );
	space /= 2;



	printf( "%d", node->pLeft->nKey );
	Space( space );

	printf( "%d\n\n\n", node->pRight->nKey );
	Space( space * 5 / 4 );
	space /= 2;



	
	printf( "%d", node->pLeft->pLeft->nKey );
	Space( space );

	printf( "%d", node->pLeft->pRight->nKey );
	Space( space );

	printf( "%d", node->pRight->pLeft->nKey );
	Space( space );

	printf( "%d\n\n\n", node->pRight->pRight->nKey );
	Space( space * 9 / 4 );
	space /= 2;




	printf( "%d", node->pLeft->pLeft->pLeft->nKey );
	Space( space );

	printf( "%d", node->pLeft->pLeft->pRight->nKey );
	Space( space );

	printf( "%d", node->pLeft->pRight->pLeft->nKey );
	Space( space );

	printf( "%d", node->pLeft->pRight->pRight->nKey );
	Space( space );

	printf( "%d", node->pRight->pLeft->pLeft->nKey );
	Space( space );

	printf( "%d", node->pRight->pLeft->pRight->nKey );
	Space( space );

	printf( "%d", node->pRight->pRight->pLeft->nKey );
	Space( space );

	printf( "%d\n\n\n", node->pRight->pRight->pRight->nKey );
	Space( space * 17/4 );
	space /= 2;


	
	printf( "%d", node->pLeft->pLeft->pLeft->pLeft->nKey );
	Space( 2 * space );


	printf( "%d", node->pLeft->pLeft->pRight->pLeft->nKey );
	Space( 2 * space );

	printf( "%d", node->pLeft->pRight->pLeft->pLeft->nKey );
	Space( 4 * space );

	printf( "%d", node->pRight->pLeft->pLeft->pLeft->nKey );
	Space( 4 * space );

	printf( "%d", node->pRight->pRight->pLeft->pLeft->nKey );

}




void FreeTree( Tree** node ) {
	if( !*node ) {
		return;
	}
	FreeTree( &((*node)->pLeft) );
	FreeTree( &((*node)->pRight) );

	free( *node );
	*node = NULL;
}






