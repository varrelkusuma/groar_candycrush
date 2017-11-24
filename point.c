#include <stdio.h>
#include <math.h>
#include "point.h"

Point makePoint(int x, int y){
/* Membentuk sebuah Point dari komponen-komponennya */
	Point P;
	P.x = x;
	P.y = y;

	return P;
}

int getAbsis(Point P){
/*Mengirimkan komponen Absis dari P*/
	return P.x;
}

int getOrdinat (Point P){
/* Mengirimkan komponen Ordinat dari P*/
	return P.y;
}

void bacaPoint(Point *P){
/*Makepoint (x,y,P) membentuk P dari x dan y yang dibaca */
	int x, y;
	printf("x : ");
	scanf("%d", &x);
	printf("y : ");
	scanf("%d", &y);

	*P = makePoint(x, y);
}

void tulisPoint(Point P){
/* Nilai P ditulis ke layar dg format “(X,Y)” */
	printf("(%d, %d)", P.x, P.y);
}

bool isEqual (Point P1, Point P2){
//Mengirimkan true jika P1=P2 : absis dan ordinatnya sama
	return (P1.x == P2.x) && (P1.y == P2.y);
}

bool isLessThan(Point P1, Point P2){
/* Mengirimkan true jika P1 < P2. Definisi lebih kecil: lebih “kiribawah”
dalam bidang kartesian */
	return (P1.x < P2.x) && (P1.y < P2.y);
}

bool isGreaterThan(Point P1, Point P2){
/* Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih “kananatas”
dalam bidang kartesian */
	return (P1.x > P2.x) && (P1.y > P2.y);
}

int kuadran(Point P){
/* Menghasilkan kuadran dari P: 1,2,3, atau 4 Prekondisi : P bukan Titik Origin, dan P tidak terletak di salah satu sumbu*/
	Point origin = makePoint(0,0);

	if(isGreaterThan(P, origin)){
		return 1;
	}
	else if(isLessThan(P, origin)){
		return 3;
	}
	else if(P.y > 0){
		return 2;
	}
	else{
		return 4;
	}

}

Point tambah(Point P1, Point P2){
//Menghasilkan operasi penjumlahan vector P1+P2
	Point P;

	int x = P1.x + P2.x;
	int y = P1.y + P2.y;

	P = makePoint(x, y);
	return P;
}

Point kurang(Point P1, Point P2){
//Menghasilkan operasi pengurangan vector P1-P2
	Point P;

	int x = P1.x - P2.x;
	int y = P1.y - P2.y;

	P = makePoint(x, y);
	return P;
}

float jarak(Point P1, Point P2){
//Menghasilkan jarak P1 dengan P2
	return sqrt(pow(P1.x-P2.x, 2) + pow(P1.y-P2.y, 2));
}
