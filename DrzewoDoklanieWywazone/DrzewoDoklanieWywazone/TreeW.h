#pragma once



typedef struct Tree {
	int nKey;
	struct Tree* pLeft;
	struct Tree* pRight;
}Tree;



Tree* CreateTree( int size );
void FreeTree( Tree** node );
void PrintTree( Tree* node, int space );
void PrintTree2( Tree* node, int space );






