#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0
#ifndef point_H
#define point_H
/* Definisi ABSTRACT DATA TYPE POINT */
typedef struct{
    int x;
    int y;
} Point;
Point makePoint(int x, int y);
/* Membentuk sebuah Point dari komponen-komponennya */
int getAbsis(Point P);
/*Mengirimkan komponen Absis dari P*/
int getOrdinat (Point P);
/* Mengirimkan komponen Ordinat dari P*/
void bacaPoint(Point *P);
/*Makepoint (x,y,P) membentuk P dari x dan y yang dibaca */
void tulisPoint(Point P);
/* Nilai P ditulis ke layar dg format “(X,Y}” */
bool isEqual (Point P1, Point P2);
//Mengirimkan true jika P1=P2 : absis dan ordinatnya sama
bool isLessThan(Point P1, Point P2);
/* Mengirimkan true jika P1 < P2. Definisi lebih kecil: lebih “kiribawah”
dalam bidang kartesian */
bool isGreaterThan(Point P1, Point P2);
/* Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih “kananatas”
dalam bidang kartesian */
int kuadran(Point P);
/* Menghasilkan kuadran dari P: 1,2,3, atau 4
 Prekondisi : P bukan Titik Origin,
 dan P tidak terletak di salah satu sumbu*/
Point tambah(Point P1, Point P2);
//Menghasilkan operasi penjumlahan vector P1+P2
Point kurang(Point P1, Point P2);
//Menghasilkan operasi pengurangan vector P1-P2
float jarak(Point P1, Point P2);
//Menghasilkan jarak P1 dengan P2
#endif