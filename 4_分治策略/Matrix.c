#include <stdio.h>
#include <stdlib.h>

typedef int real;

struct _Matrix
{
	real *data;
	int row;
	int col;
};

typedef struct  _Matrix Matrix;

//show Matrix
void printMatrix(const Matrix *pMatrix);

//create Matrix
int createMatrix(Matrix **pMatrix,int row,int col,real *data);

//free Matrix struct
int freeMatrix(Matrix *pMatrix);

//Matrix add
int addMatrix(Matrix *pMatrix,Matrix *pAddMatrix);

//Multiply Matrix
int multiplyMatrix(Matrix *pMatrix,Matrix *pMul,Matrix **pResult);

int main()
{
	real m1[] = { 1,2,3,4,
					  1,2,3,4,
					  1,2,3,4,
					  1,2,3,4};
	real m2[] = { 2,0,0,0,
					  0,2,0,0,
					  0,0,2,0,
					  0,0,0,2};
	Matrix *pMatrix = NULL;
	Matrix *pMatrix2 = NULL;
	Matrix *pMatrix3 = NULL;
	createMatrix(&pMatrix,4,4,m1);
	createMatrix(&pMatrix2,4,4,m2);
	printMatrix(pMatrix);
	printMatrix(pMatrix2);

	multiplyMatrix(pMatrix, pMatrix2, &pMatrix3);
	
	printMatrix(pMatrix3);
	freeMatrix(pMatrix);
	freeMatrix(pMatrix2);
	freeMatrix(pMatrix3);
	return 0;
}

void printMatrix(const Matrix *pMatrix)
{
	int i,j;
	int row,col;
	
	if(pMatrix == NULL) return;

	row = pMatrix->row;
	col = pMatrix->col;
	for(i = 0; i < row ;i++)
	{
		int offet = i * col;
		for(j = 0; j < col ;j++)
		{
			printf("%d     ",pMatrix->data[offet + j]);
		}//end for j
		printf("\n");
	}//end for i
}

//create Matrix
int createMatrix(Matrix **pMatrix,int row,int col,real *data)
{
	int i;
	real *pData = NULL;
	Matrix * pM = (Matrix *) malloc(sizeof(Matrix));
	if(pM == NULL)
	{
		return -1;
	}
	
	pM->row = row;
	pM->col = col;
	int dataSize = row * col;
	
	pData = (real *)malloc(dataSize * sizeof(real));
	if(pData == NULL || data == NULL)
	{
		free(pM);
		return -1;
	}
	
	for(i = 0; i< dataSize ; i++)
	{
		pData[i] = data[i];
	}//end for i
	pM->data = pData;
	*pMatrix = pM;

	return 0;
}

//free Matrix struct
int freeMatrix(Matrix *pMatrix)
{
	if(pMatrix == NULL)
	{
		return 0;
	}

	real *pData = pMatrix->data;
	if(pData!=NULL)
	{
		free(pData);
	}
	free(pMatrix);

	return 0;
}	

int addMatrix(Matrix *pMatrix,Matrix *pAddMatrix)
{
	if(pMatrix->row != pAddMatrix->row  || pMatrix->col != pAddMatrix->col)
		return -1;

	int row,col;
	int i,j;
	row = pMatrix->row;
	col = pMatrix->col;
	for(i = 0; i < row ;i++)
	{
		int offet = i * col;
		for(j = 0; j < col ;j++)
		{
			pMatrix->data[offet + j] += pAddMatrix->data[offet + j];
		}//end for j
	}//end for i

	return 0;
}

//Multiply Matrix
int multiplyMatrix(Matrix *pMatrix,Matrix *pMul,Matrix **pResult)
{
	int row = pMatrix->row;
	int col = pMul->col;
	int i,j,k;
	Matrix *pResultMatirx = NULL;

	if(pMatrix->col != pMul->row)
	{
		return -1;
	}

	real *pResultData = (real *)malloc(row * col*sizeof(real));
	
	int total = 0;
	for(i =0;i<row;i++)
	{
		for(j = 0;j<col;j++)
		{
			real result = 0;

			for(k = 0;k<col;k++)
			{
				result += (pMatrix->data[col * i+k]) * (pMul->data[col * k+ j]);
			}
			pResultData[col * i +j] = result;
		}//end for j
		//printf("\n");
	}//end for i
	
	//pResultMatirx = (Matrix *)malloc(sizeof(Matrix));
	//pResultMatirx->row = row;
	//pResultMatirx->col = col;
	//pResultMatirx->data = pResultData;
	createMatrix(&pResultMatirx, row, col, pResultData);
	*pResult = pResultMatirx;
	return 0;
}
