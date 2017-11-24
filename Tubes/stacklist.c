#include "stacklist.h"

//Konstruktor/Kreator 
void CreateEmpty (Stack *S){
// I.S. Sembarang 
// F.S. Membuat sebuah stack S yang kosong 
// Ciri stack kosong : TOP bernilai Nil 
	Top(*S) = Nil;	
}

// Prototype manajemen memori
void Alokasi (address *P, infotype X){
// I.S. P Sembarang, X terdefinisi 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil 
// P = Nil jika alokasi gagal 
	*P = (address) malloc(sizeof(ElmtStack));
	if(*P != Nil){
		Info(*P) = X;
		Next(*P) = Nil;
	}
}
void Dealokasi (address *P){
// I.S. P adalah hasil alokasi, P != Nil 
// F.S. Alamat P didealokasi, dikembalikan ke sistem 
	free(*P);
}

// Predikat Untuk test keadaan KOLEKSI
bool IsEmpty (Stack S){
// Mengirim true jika Stack kosong
	return Top(S) == Nil;
}

// Operator Dasar Stack
void Push (Stack *S, infotype X){
// Menambahkan X sebagai elemen Stack S. 
// I.S. S mungkin kosong
// F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. 
// Jika alokasi gagal, S tetap. 
	address ins;
	Alokasi(&ins, X);
	if (ins != Nil)	{
		address P = Top(*S);
		Next(ins) = P;
		Top(*S) = ins;
	}
}

void Pop (Stack *S, infotype *X){
// Menghapus X dari Stack S. 
// I.S. S tidak kosong 
// F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi, 
// TOP(S) = Next(TOP(S)). 
	address P = Top(*S);
	*X = Info(P);
	Top(*S) = Next(P);
	Dealokasi(&P);
}

bool equal(infotype a, infotype b){
	return (a.x == b.x) && (a.y == b.y);
}
address Search (Stack S, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
	address P = Top(S);
	if (IsEmpty(S)){
		return Nil;
	}else{
		while( (Next(P) != Nil) && (!equal(X, Info(P)) ) ){
			P = Next(P);
		}
		if (equal(X, Info(P))){
			return P;
		}else{
			return Nil;
		}
	}
}

void PushUnique (Stack *S, infotype X){
// Menambahkan X sebagai elemen Stack S jika unik. 
// I.S. S mungkin kosong
// F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil. 
// Jika alokasi gagal, S tetap. 
	address member = Search(*S, X);

	if (member == Nil){
		Push(S, X);
	}
}