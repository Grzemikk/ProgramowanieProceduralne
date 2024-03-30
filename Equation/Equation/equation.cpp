#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matrix.h"

#define _DEBUG_

void ReadData( FILE* fin, double** pMatrix, double* b, int nDim );
int CreateVector( double** pVec, int nDim );
void PrintVector( double* pVec, int nDim );

int main( int argc, char* argv[] ) {
	if( argc != 2 ) {
		printf( "Usage: %s <input_file>\n", argv[0] );
		return 1;
	}

	FILE* fin = NULL;

	if( ( fin = fopen( argv[1], "rt" ) ) == NULL ) {
		perror( "File open Error\n" );
		return -1;
	}

	double** pMatrix = NULL;
	int nDim = 0;

#ifdef _DEBUG_
	fscanf( fin, "%d", &nDim );
#endif

	if( !CreateMatrix( &pMatrix, nDim ) ) {
		perror( "pMatrtix Error" );
		return -2;
	}

	double* pVector = NULL;

	if( !CreateVector( &pVector, nDim ) ) {
		printf( "pVector Error" );
		return -3;
	}

	ReadData( fin, pMatrix, pVector, nDim );
#ifdef _DEBUG_
	printf( "Loaded Matrix:\n" );
	PrintMatrix( pMatrix, nDim );
	printf( "\nVector of solutions: \n" );
	PrintVector( pVector, nDim );
#endif

	double det = Det( pMatrix, nDim );

#ifdef _DEBUG_
	printf( "\nDet: %.2f \n", det );
#endif

	if( fabs( det ) < 1e-205 ) {
		printf( "Matrix is singular" );
		return -4;
	}

	double** MatInv = NULL;
	if( !CreateMatrix( &MatInv, nDim ) ) {
		perror( "MatInv Error" );
		return -5;
	}

	InverseMatrix( MatInv, pMatrix, nDim, det );
#ifdef _DEBUG_
	printf( "Inverse Matrix: \n" );
	PrintMatrix( MatInv, nDim );
	printf( "\n" );
#endif

	double* VecRes = NULL;
	if( !CreateVector( &VecRes, nDim ) ) {
		perror( "VecRes Error" );
		return -5;
	}

	LayoutEqu( MatInv, pVector, VecRes, nDim );
	printf( "Solution: \n" );
	PrintVector( VecRes, nDim );
	DeleteMatrix( &pMatrix, nDim );
	DeleteMatrix( &MatInv, nDim );
	free( VecRes );
	free( pVector );

	return 0;
}
 
void ReadData( FILE* fin, double** pMatrix, double* b, int nDim ) {
	for( int i = 0; i < nDim; i++ ) {
		double* w = *pMatrix++;
		for( int j = 0; j < nDim; j++ ) {
			fscanf( fin, "%lf", w++ );
		}
		fscanf( fin, "%lf", b++ );
	}
}

int CreateVector( double** pVec, int nDim ) {
	*pVec = (double*) malloc( nDim * sizeof( double ) );
	if( !*pVec ) {
		return 0;
	}
	memset( *pVec, 0, nDim * sizeof( double ) );

	return 1;
 }

void PrintVector( double* p, int nDim ) {
	for( int i = 0; i < nDim; i++ ) {
		printf( "%.2lf \n", *p++ );
	}
}





//szkic main( int argc, char* argv[] )

	// sprwdzic argumenty main
	// odtworzyc plik do odczytu (tekstowy)
	// odczytac rozmiar nDim   fscanf( fin, "%d\n", &nDim ); // nDim param WY   fin plik po otwarciu do odczytu

	// wykreowac macierz pMatrix ukladu nDim x nDim
	// wykreowac wektor wyrazow wolnych b
	// wczytac dane ( ReadData() )

//wydruk kontrolny (warunkowa kompilacja)

	// obl wyznacznik
//wydruk kontrolny (warunkowa kompilacja)
	// obrocic macierz

//wydruk kontrolny  (warunkowa kompilacja)

	// wykreowac wektor wynikowy
	// rozwiazac ukl
	// wyniki
	// zwolnic pamiec !!!

