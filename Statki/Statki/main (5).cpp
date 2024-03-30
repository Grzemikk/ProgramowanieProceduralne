/*==================
BACKTRACKING  algorytm z nawrotami
-------------
ogólny algorytm wyszukiwania wszystkich (lub kilku) rozwi¹zañ niektórych problemów
obliczeniowych, który stopniowo generuje kandydatów na rozwi¹zanie jednak,
gdy stwierdzi, ¿e znaleziony kandydat x nie mo¿e byæ poprawnym rozwi¹zaniem,
nawraca (ang. "backtracks") do punktu, gdzie mo¿e podj¹æ inn¹ decyzje
zwi¹zan¹ z jego budow¹
==============================*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"ship.h"

//zdefini stale N i M - wymiary  (na 10)  tam gdzie main()
// glebokosc zanurzenia okretu   tam gdzie main()

#define DEPTH_MIN 5
#define NROW 10
#define NCOL 10

int** CreateTab2D( int nCol, int nRow );
void PrintMatrix( int** pTab, int nRow, int nCol );
void DeleteMatrix( int*** pTab ); 

int main( int argc, char* argv[] )
{
  if( argc != 2 ) {
    printf( "Usage: %s <input_file>\n", argv[0] );
    return 1;
  }    //!!argc

  //Wykreowac dynamicznie dwie tablice dwuwymiarowe (ogolnie moga byc rozne wymiary)
  // wykorzystac funkcje z matrixa ale dodac parametr z drugim wymiarem

  int** pTab = CreateTab2D( NCOL, NROW );
  int** pRoot = NULL;
  if( !pTab ) {
    printf( "Allocation Error\n" );
    return -1;
  }
  if( ( pRoot = CreateTab2D( NCOL, NROW ) ) == 0 ) {
    printf( "Allocation Error\n" );
      return -2;
  }
  
  if( setTab( argv[1], pTab, NROW, NCOL ) == 0 ) {
    printf( "File mapa.txt open Error\n" );
      return -3;
  }
  // wyzerowac obie tablice 
// wczytac dane (sprawdzic argc)  glebokosci 

  printf( "Ship immersion: %d\nMap:\n", DEPTH_MIN );
  PrintMatrix( pTab, NROW, NCOL );
  printf( "\n" );



  // Jezeli nie znaleziono drogi od (0,0) do (N,M)- funkcja rekur root - wypisac
  //"** Nie ma mozliwosci doplynac do portu!!\n\n";
    if( root( pTab, NROW, NCOL, DEPTH_MIN, 0, 0, pRoot, NROW - 1, NCOL - 1 ) == 0 ) {
      printf( "There is no way to reach the port!!\n\n" );
  }
    else {   // jesli ok to wypisac trase
      printf( "\n Way: \n" );
      PrintMatrix( pRoot, NROW, NCOL );
    }

    DeleteMatrix( &pTab );
    DeleteMatrix( &pRoot );

  //zwolnic pamiec!!
  return 0;
}


//kreowanie druga metoda
int** CreateTab2D( int nCol, int nRow ) 
{
  int** pTab = (int**)malloc( sizeof( int* ) * nRow ); //adresy kolejnych wierszy tablicy dwuwymiarowej
    if (!pTab) return NULL;
    memset( pTab, 0, sizeof( int* ) * nRow );

    *pTab = (int*)malloc( sizeof( int ) * nRow * nCol );
    if( !*pTab, 0, sizeof( int ) * nRow * nCol );
    memset( *pTab, 0, sizeof( int ) * nRow * nCol );

    int** k = pTab + 1;
    int* p = *pTab + nCol;

    for( int i = 1; i < nRow; i++, p += nCol ) *k++ = p;
    return pTab;
}

void DeleteMatrix( int*** pTab ) {
  free( **pTab );
  free( *pTab );
  *pTab = NULL;
}

void PrintMatrix( int** pTab, int nRow, int nCol ) {
  for( int i = 0; i < nRow; i++ ) {
    int* k = *pTab++;
    for( int j = 0; j < nCol; j++ ) {
      printf( "%d ", *k++ );
    } printf( "\n" );
  }
}