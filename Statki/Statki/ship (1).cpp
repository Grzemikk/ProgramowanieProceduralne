#include<stdio.h>
#include<memory.h>
#include"ship.h"

// modul:   ship.cpp  ship.h
// zdefiniowac typ wyliczeniowy: kierunki ruchu : UP RIGHT DOWN LEFT  (wartosci kolejne od 0)

typedef enum { UP, RIGHT, DOWN, LEFT } Move;


void clearRoot( int** pRoot, int nRow, int nCol )
{
  memset( *pRoot, 0, nRow * nCol * sizeof( int ) );
}
  

int setTab( char* sFile, int** pTab, int nRow, int nCol )
// wczytuje dane z pliku
// sFile -  nazwa pliku wejsciowego - parametr main()
// pTab  - tablica glebokosci morza
// nRow, nCol wymiary tej tablicy
{
  FILE* fin = NULL;

  if( ( fin = fopen( sFile, "r" ) ) == NULL ) {
    perror( "Error open mapa.txt input file \n" );
    return 0;
  }

  for( int i = 0; i < nRow; i++ ) {
    int* k = *pTab++;
    for( int j = 0; j < nCol; j++ ) {
      fscanf( fin, "%d", k++ );
    }
  }
  fclose( fin );
  return 1;
}
//-------------------------------------------------------------
int move( int** pTab, int nRow, int nCol, int nDepth,
  int move, int x, int y, int* px, int* py, int** pRoot )
{
  // pTab - tablica okreslajaca glebokosc w kazdym kwadracie
  // nRow, nCol - rozmiar pTab,
  // nDepth - minimalna glebokosc aby statek przeplynal
  // move - kierunek ruchu (wart typu wylicz)
  // x  y - wsporzedne skad robimy nowy ruch
  //  wykonac kolejny ruch w kierunku move obliczajac nowe wspolrzedne *px *py
       //(switch)
  switch( move )
  {
  case UP: *px = x;  *py = y + 1; break;
  case RIGHT: *px = x + 1; *py = y; break;
  case DOWN: *px = x;  *py = y - 1; break;
  case LEFT: *px = x - 1; *py = y; break;
  }

  if( *px < 0 || *py >= nCol || *py < 0 || *px >= nRow ) return 0;    //sprawdzic czy nowe indeksy *px i *py sa w zakresie indeksow tablicy
  if( pTab[*px][*py] <= nDepth ) return 0;     // a nastepnie sprawdzic warunek czy nie jest za plytko ">nDepth " oraz
  if( pRoot[*px][*py] != 0 ) return 0;    // czy nie bylo sie juz w lokalizacji (*px,*py) - wg tabl pRoot (wart 0 w nowej lokalicacji)
  return 1;  //    jesli wszystkie warunki poprawne to zwracamy 1
  //    else 0
}

//----------------------------------------------------------------------------------
int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot,
  int x_dest, int y_dest )
{
  // tabl pRoot pamieta droge   -   numer ruchu pole przez ktore odwiedzono (plynie statek) 
  // 0 pole nie odwiedzone
  // wstawic do tablicy pRoot kolejny numer ruchu
  static int k = 1;
  pRoot[x][y] = k++;

  if( x == x_dest && y == y_dest ) return 1;

  int px = x;
  int py = y;

  for( int i = UP; i <= LEFT; i++ )
  {
    if( move( pTab, nRow, nCol, nDepth, i, x, y, &px, &py, pRoot ) )
    {
      if( root( pTab, nRow, nCol, nDepth, px, py, pRoot, x_dest, y_dest ) ) return 1;
    }
  }

  pRoot[x][y] = 0;
  k--;

  //else
  // zdefiniowac nowe wspolrzende 
  // sprwadzic wszystkie mozliwosci ruchu
  //jesli ruch jest mozliwy w zadanym kierunku 
  //jesli wykonanie kolejnego kroku sie powiodlo - rekurencyjnie root()
  // jesli wracamy to ustawiamy w pRoot ze ruch byl zly
  return 0;

}


  