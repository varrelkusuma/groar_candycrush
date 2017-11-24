#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main(){
	srand(time(NULL));   // should only be called once
	Matrix m;
	Stack s;
	int r, point;

	for(int i = 0; i<Nmax; i++){
		for(int j = 0; j<Nmax; j++){
			r = (rand() % 4) + 1;
			m[i][j] = r;			
		}
	} 
	
	printMatrix(m);
	printf("\n");
	GetChain(&s, m);
	Update(&s, m,&point);
	printf("\n");
	printf("\n");
	printMatrix(m);
	RemoveZero(m);
	printf("\n");
	printf("\n");
	printMatrix(m);
	printf("point %d\n", point);

	return 0;
}