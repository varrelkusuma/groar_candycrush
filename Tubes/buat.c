#include <stdio.h>
#include <stdlib.h>

int random(void) {
    int x;

    srand(time(NULL));
    x = rand() % 5;
    return x;
}

void printMatrix(Matrix m[Nmax][Nmax]){
	for(int i = 0; i<8; i++){
		printf("+-------------------------------+\n");
		printf("|");
		for(int j = 0; j<8; j++){
			printf(" %d |", m[i][j]);			
		}
		printf("\n");
	}
	printf("+-------------------------------+\n");
}