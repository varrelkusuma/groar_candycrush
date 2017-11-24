#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stacklist.h"

#define Nmax 8
typedef int Matrix;

infotype CreateCoor(int x, int y){
	infotype c;
	c.x = x;
	c.y = y;
	return c;
}

void printMatrix(Matrix m[Nmax][Nmax]){
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			printf("%d ", m[i][j]);			
		}
		printf("\n");
	} 
}

void Update(Stack *S, Matrix m[Nmax][Nmax], int *point){
//  I.S. S terdefinisi, m terdefinisi, point sembarang
//	F.S. semua m dengan koordinat dalam stack nilainya 0 point berisi banyak koordinat rantai
	infotype c;
	int count = 0;
	while(!IsEmpty(*S)){
		Pop(S, &c);
		count++;
		m[c.x][c.y] = 0;
	}

	*point = count;
}

void CountPoint(Stack *S, Matrix m[Nmax][Nmax]){
// I.S. stack s sembarang, matrix m terdefinisi
//  F.S stack s terisi dengan semua koordinat rantai
	CreateEmpty(S);
	int after, after2;
	int cek;
	int count;
	for (int i = 0; i < Nmax; i++)
	{
		count = 0;
		for (int j = 0; j < Nmax-2; j++)
		{
			cek = m[i][j];
			after = m[i][j+1];
			after2 = m[i][j+2];
			//printf("cek = %d, after = %d, after2 = %d\n", cek, after, after2);

			if((cek == after) && (cek == after2)){
				// jika ada yang rantai yang sama minimal 3
				printf("\n");
				do{
					// printf("masuk\n");
					printf("(%d,%d)", i, j);
					PushUnique(S, CreateCoor(i,j));
					j++;
				}while((j<Nmax) && (m[i][j] == cek));
			}
		}
	}

	for (int i = 0; i < Nmax; i++)
	{
		count = 0;
		for (int j = 0; j < Nmax-2; j++)
		{
			cek = m[j][i];
			after = m[j+1][i];
			after2 = m[j+2][i];
			//printf("cek = %d, after = %d, after2 = %d\n", cek, after, after2);

			if((cek == after) && (cek == after2)){
				printf("\n");
				do{
					// printf("masuk\n");
					printf("(%d,%d)", j, i);
					PushUnique(S, CreateCoor(j,i));
					j++;
				}while((j<Nmax) && (m[j][i] == cek));
			}
		}
	}

}


int main(){
	srand(time(NULL));   // should only be called once
	Matrix candy[Nmax][Nmax];
	Stack s;
	int r, point;

	for(int i = 0; i<Nmax; i++){
		for(int j = 0; j<Nmax; j++){
			r = (rand() % 4) + 1;
			candy[i][j] = r;			
		}
	} 

	printMatrix(candy);
	printf("\n");
	CountPoint(&s, candy);
	Update(&s, candy,&point);
	printf("\n");
	printf("\n");
	printMatrix(candy);
	printf("point %d\n", point);

	return 0;
}