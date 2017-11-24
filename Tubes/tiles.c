#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "gconio.h"
#include "stacklist.h"

#define Nmax 8
typedef int Matrix;

infotype CreateCoor(int x, int y){
	infotype c;
	c.x = x;
	c.y = y;
	return c;
}

void AcakIsi (Matrix m[Nmax][Nmax]) {
	/* KAMUS LOKAL */
	int r;

	/* ALGORITMA */
	for(int i = 0; i<Nmax; i++){
		for(int j = 0; j<Nmax; j++){
			r = (rand() % 4) + 1;
			m[i][j] = r;			
		}
	} 
}

void PrintKotak (Matrix m[Nmax][Nmax]) {
/* KETENTUAN WARNA BUAH
	1 = Merah == &&
	2 = Hijau == ##
	3 = Biru == $$
	4 = Orange == @@
*/
	/* ALGORITMA */
	printf("\n");
	for(int i = 0; i<8; i++) {
		textcolor(15);
		printf("+---------------------------------------+");
		printf("\n");
		printf("|");
		for(int j = 0; j<8; j++) {
			if (m[i][j] == 1) {
				textcolor(4); // RED
				printf(" && ");
			}
			else if (m[i][j] == 2) {
				textcolor(2); // GREEN
				printf(" ## ");
			}
			else if (m[i][j] == 3) {
				textcolor(1); // BLUE
				printf(" $$ ");
			}
			else {
				textcolor(14); // ORANGE
				printf(" @@ ");
			}
			textcolor(15);
			printf("|");
		}
		printf("\n");
	}
	textcolor(15);
	printf("+---------------------------------------+\n");
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
	
	AcakIsi(candy);
	PrintKotak(candy);
	printf("\n");

	printf("Haihaihai\n");

	return 0;
}