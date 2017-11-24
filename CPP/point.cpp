#include <iostream>
#include "point.h"

using namespace std;

//  Constructor //
Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

//  Destructor  //
Point::~Point() {

}

//  GETTER //
int Point::GetAbsis() {
    return x;
}

int Point::GetOrdinat() {
    return y;
}

//  SETTER  //
void Point::SetAbsis (int _x) {
    x = _x;
}

void Point::SetOrdinat(int _y) {
    y = _y;
}

//  PREDIKAT    //

int Point::IsOrigin() {
    /* KAMUS LOKAL */
    int hasil;
    /* ALGORITMA */
    if ((x == 0) && (y == 0)) {
        hasil = 1;
    }
    else {
        hasil = 0;
    }
    return hasil;
}

int Point::IsEqual(Point P) {

    if ((x = P.x) && (y = P.y)) {
        
    }

}

void Point::AddToMe(int a, int b) {

    x = x + a;
    y = y + b;

}