#pragma once

#define LISTINFO Info

typedef struct {
	int key;
}Info;


int compare( const void*, const void* );
void freeMem( const void* );
void print( const void* );

