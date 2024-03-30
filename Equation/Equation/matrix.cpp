#include<stdlib.h>
#include<stdio.h>
#include<memory.h>
#include"matrix.h"


int CreateMatrix( double*** pTab, int nDim ) {
  *pTab = (double**) malloc( nDim * sizeof( double* ) );
  if( !*pTab ) {
    perror( "CreateMatrix Erorr\n" );
    return 0;
  }

  memset( *pTab, 0, nDim * sizeof( double* ) );
  double** pTemp = *pTab;

  for( int i = 0; i < nDim; i++, pTemp++ ) {
    *pTemp = (double*) malloc( nDim * sizeof( double ) );
    if( !*pTemp ) {
      perror( "CreateMatrix Error\n" );
      return 0;
    }
    memset( *pTemp, 0, nDim * sizeof( double ) );
  }

  return 1;
}

void DeleteMatrix( double*** pTab, int nDim ) {
  double** p = *pTab;
  for( int i = 0; i < nDim; i++ ) {
    free( *p++ );
  }
  free( *pTab );
  *pTab = NULL;
}

void PrintMatrix( double** pTab, int nDim ) {
  for( int i = 0; i < nDim; i++ ) {
    double* k = *pTab++;
    for( int j = 0; j < nDim; j++ ) {
      printf( "%.2lf ", *k++ );
    }
    printf( "\n" );
  }
}

void TransMatrix( double** pTab, int nDim ) {
  double** k = pTab;
  for( int i = 0; i < nDim - 1; i++ ) {
    double* w = *k++ + i + 1;
    for( int j = i; j < nDim; j++ ) {
      double temp = *w;
      *w++ = pTab[j][i];
      pTab[j][i] = temp;
    }
  }
}

double Det( double** pTab, int nDim ) {
  if( nDim == 1 ) return **pTab;
  if( nDim == 2 ) return pTab[0][0] * pTab[1][1] - pTab[0][1] * pTab[1][0];

  double** pTemp = NULL;
  if( !CreateMatrix( &pTemp, nDim - 1 ) ) {
    perror( "Det Error" );
    return 0;
  }
  double det = 0;
  double sign = 1;
  double* p = *pTab;
  for( int i = 0; i < nDim; i++, p++ ) {
    Complement( pTemp, pTab, 0, i, nDim );
    det += *p * Det( pTemp, nDim - 1 ) * sign;
    sign = -sign;
  }
  DeleteMatrix( &pTemp, nDim - 1 );
  return det;
}


void Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim ) {
  for( int i = 0; i < nDim; i++, pTabI++ ) {
    if( i == nRow ) continue;
    double* x = *pTabO++;
    double* y = *pTabI;
    for( int j = 0; j < nDim; j++, y++ ) {
      if( nCol == j ) continue;
      *x++ = *y;
    }
  }
}

void ComplMatrix( double** pTabD, double** pTab, int nDim ) {
  double** pTabTemp = NULL;
  if( !CreateMatrix( &pTabTemp, nDim - 1 ) ) {
    perror( " ComplMatrix Error" );
    return;
  }
  for( int i = 0; i < nDim; i++ ) {
    int sign = ( i % 2 ) ? -1 : 1;
    double* k = *pTabD++;
    for( int j = 0; j < nDim; j++ ) {
      Complement( pTabTemp, pTab, i, j, nDim );
      *k++ = Det( pTabTemp, nDim - 1 ) * sign;
      sign = -sign;
    }
  }
  DeleteMatrix( &pTabTemp, nDim - 1 );
}


void InverseMatrix( double** pInv, double** pTab, int nDim, double det ) {
  ComplMatrix( pInv, pTab, nDim );
  TransMatrix( pInv, nDim );
  for( int i = 0; i < nDim; i++ ) {
    double* v = *pInv++;
    for( int j = 0; j < nDim; j++ ) {
      *v++ /= det;
    }
  }
}

void LayoutEqu( double** pInv, double* pB, double* pRes, int nDim ) {
  for( int i = 0; i < nDim; i++, pRes++ ) {
    double* pTemp = *pInv++;
    double* bTemp = pB;
    for( int j = 0; j < nDim; j++, pTemp++, bTemp++ ) {
      *pRes += ( *pTemp ) * ( *bTemp );
    }
  }
}

