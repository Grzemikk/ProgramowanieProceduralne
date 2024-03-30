#ifndef _MATRIX_H
#define _MATRIX_H

int  CreateMatrix(double*** pTab, int nDim);   //!!! zwraca 0  gdy error lub  1 - gdy ok
void DeleteMatrix( double*** pTab, int nDim );  // *pTab=NULL na konuc
void PrintMatrix( double** pTab, int nDim );
void TransMatrix(double** pTab, int nDim);
void InverseMatrix(double** pInv, double** pTab, int nDim, double det);
double Det(double** pTab, int nDim);
void LayoutEqu(double** pInv, double* pB, double* pRes, int nDim);
void Complement(double** pTabO, double** pTabI, int nRow, int nCol, int nDim);
void ComplMatrix(double** pTabD, double** pTab, int nDim);

#endif