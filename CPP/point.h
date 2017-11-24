// File : point.h
// Matrikulasi Dago Hoogeschool 2017
// Tugas Individu
// Kumpulkan file ini bersama point.cpp dan main.cpp

#ifndef __POINT_H__
#define __POINT_H__

class Point {
public:
    // Constructor
    // Titik secara default memiliki nilai x = 0 dan y = 0
    Point();
    // Constructor dengan parameter
    Point(int _x, int _y);
    // Destructor
    ~Point();
    // Getter
    int GetAbsis();
    int GetOrdinat();
    // Setter
    void SetAbsis (int _x);
    void SetOrdinat (int _y);
    // Predikat
    // Menghasilkan 1 jika titik (x, y) berada di (0, 0) dan 0 apabila sebaliknya 
    int IsOrigin();
    // Operator Relasional
    // Menghasilkan 1 jika titik pada argumen sama dengan dirinya (nilainya x dan y sama) dan 0 apabila sebaliknya
    int IsEqual(Point P);
    // Operator Aritmatika
    // Mengubah titik dengan penambahan Point argumen
    void AddToMe(Point P);
    // Mentranslasikan titik sebesar (x, y)
    void AddToMe(int a, int b);
    // Mengubah titik yang merupakan hasil mirror dengan garis y = x
    void Mirror();
    // Menghasilkan nomor kuadran dari titik sekarang
    // Sebuah titik yang berada pada sumbu x atau y tidak akan dicoba 
    int Kuadran();
private:
    int x; //Absis
    int y; //Ordinat
};

#endif