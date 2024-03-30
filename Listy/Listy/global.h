// include global.h which should be defined by the user !!!
  // w pliku global.h 
  //  zdefinowac typ uzytkonika - zgdonie z opisem 
#pragma once

typedef struct {
  int nKey;
  int* p;
} ListInfo;

#define LISTINFO ListInfo


void freeMem( const void* );
int compare( const void*, const void* );

