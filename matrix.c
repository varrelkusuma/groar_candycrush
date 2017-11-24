#include "matrix.h"

void swap(candy *a, candy *b){
	candy temp = *a;
	*a = *b;
	*b = temp;
}

void printMatrix(Matrix m){
	for(int i = 0; i<8; i++){
		printf("|");
		for(int j = 0; j<8; j++){
			printf("  %d   |", m[i][j]);			
		}
		printf("\n+");
		for(int j = 0; j<8; j++){
			printf("------+", m[i][j]);			
		}
		printf("\n");
	} 
}

void Update(Stack *S, Matrix m, int *score){
//  I.S. S terdefinisi, m terdefinisi, point sembarang
//	F.S. semua m dengan koordinat dalam stack nilainya 0 point berisi banyak koordinat rantai
	Point c;
	int count = 0;
	while(!IsEmpty(*S)){
		Pop(S, &c);
		count++;
		m[c.x][c.y] = 0;
	}

	*score = count;
}

void RemoveZero(Matrix m){
	int k;
	int above;
	bool swapped;
	for (int i = 0; i < Nmax; i++){
		k = Nmax;
		for (int j = Nmax-1; j >= 0; j--){
			swapped = false;
			if(m[j][i]==0){
				k = j;
				do{
					k--;
					if(k>=0){
						above = m[k][i];	
						if(above != 0){
							swap(&m[j][i],&m[k][i]);
							swapped = true;
						}
					}
				}while((k>=0) && !swapped);
			}
		}
	}
}

void GetChain(Stack *S, Matrix m){
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
				do{
					// printf("masuk\n");
					PushUnique(S, makePoint(i,j));
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
				do{
					PushUnique(S, makePoint(j,i));
					j++;
				}while((j<Nmax) && (m[j][i] == cek));
			}
		}
	}

}