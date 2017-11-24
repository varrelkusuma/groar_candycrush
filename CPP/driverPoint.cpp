#include <iostream>
#include "point.h"

using namespace std;

int main() {
    /* KAMUS LOKAL */
    Point p1, p2;
    Point p3(0,0);
    int a, b, x, y;

    /* ALGORITMA */

    /* INISIALISASI POINT 1 */
    cout << "1. Masukan letak yang dimau : " << endl;
    cout << "X : ";
    cin >> x;
    cout << "Y : ";
    cin >> y;
    p1.SetAbsis(x);
    p1.SetOrdinat(y);
    cout << "Titik 1 terletak pada : (" << p1.GetAbsis() << " : " << p1.GetOrdinat() << ")" << endl; 
    cout << endl;

    /* PERBANDINGAN */
    cout << "Apakah titik 1 origin?" << endl;
    if (p1.IsOrigin() == 1) {
        cout << "Iya :)" << endl;
    }
    else {
        cout << "Enggak :(" << endl;
    }
    cout << endl;

    /* INISIALISASI POINT 2 */
    cout << "2. Masukan letak yang dimau : " << endl;
    cout << "X : ";
    cin >> a;
    cout << "Y : ";
    cin >> b;
    p2.SetAbsis(a);
    p2.SetOrdinat(b);
    cout << "Titik 2 terletak pada : (" << p2.GetAbsis() << " : " << p2.GetOrdinat() << ")" << endl; 
    cout << endl;

    /* PERBANDINGAN 2 */
    cout << "Apakah titik 2 origin?" << endl;
    if (p2.IsOrigin() == 1) {
        cout << "Iya :)" << endl;
    }
    else {
        cout << "Enggak :(" << endl;
    }
    cout << endl;

    cout << "Tambah dua duanya yu" << endl;
    cout << "Jadinya : " << endl;
    p1.AddToMe(p2.GetAbsis(),p2.GetOrdinat());
    cout << "Sekarang ada di : (" << p1.GetAbsis() << " : " << p1.GetOrdinat() << ")" << endl;

    return 0;
}