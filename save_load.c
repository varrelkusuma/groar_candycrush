/* filename : save_load.c */
#include "save_load.h"

void inisialisasi (infotype *player)
/* I.S : player belum berisi apa-apa, nama dan skor masih kosong. Digunakan saat login */
/* F.S : player terisi nama pemain dan skor 0 */
{
	//algoritma lokal
	scanf("%49s", (*player).name);
	(*player).skor = 0;
}

void load (List *L, char filename[25])
/* I.S : file merupakan file of char, file dapat kosong dapat terisi */
/* F.S : seluruh data yang terdapat di file tersalin kedalam list */
{
	//Kamus lokal
	FILE *Fin;
	infotype x;
	char buf[100];
	//Algoritma lokal
	//inisialisasi file
	Fin = fopen(filename,"r+");
	
	if (!Fin) //apabila gagal baca file
	{
		fprintf(stderr,"Gagal membaca file\n");
		exit(1);
	}
	
	while (!feof(Fin))
	{
		fgets(buf,100,Fin);
		sscanf(buf, "%s %d\n", x.name, &x.skor);
		InsVLast(L, x);
	}
	fclose(Fin);
}
void save(List *L, char filename[25])
/* I.S : file dapat terisi sebelumnya, list tidak kosong */
/* F.S : seluruh data pada list tersalin kedalam file */
{
	//Kamus lokal
	FILE *Fout;
	infotype x;
	int count = NbElmt(*L),i = 1;
	//Algoritma lokal
	//inisialisasi file
	Fout = fopen(filename,"w");
	while (!IsEmpty(*L))
	{
		DelVFirst(L,&x);
		i++;
		if (i<=count)
			fprintf(Fout, "%s %d\n",x.name,x.skor);
		else
			fprintf(Fout, "%s %d",x.name,x.skor);
	}
	fclose(Fout);
}

void updateSkor (List *L, infotype player, int skor)
/* I.S : List terurut berdasarkan skor mengecil, list bisa kosong, 
nama player sudah ada, dan skor ada*/
/* F.S : data player yang sudah terisi nama dan skor diinput kedalam list */
{
	//Kamus lokal
	address Px,P,Prec;
	bool found;
	//Algoritma lokal
	player.skor = skor;
	if (IsEmpty(*L))
	{
		InsVFirst(L, player);
	}else
	{
		Px = Alokasi(player);
		
		//Mencari Lokasi P yang sesuai dan memasukan Px sebelum P
		P=First(*L);
		Prec = Nil;
		found = false;
		while (P!= Nil && !found)
		{
			if (Info(P).skor <= Info(Px).skor)
				found = true;
			else
			{
				Prec = P;
				P = Next(P);
			}
		}
		if (found && Prec != Nil)
		{
			Next(Px)=Next(Prec);
			Next(Prec)=Px;
		}else if (found && Prec == Nil)
		{
			Next(Px)=P;
			First(*L)=Px;
		}else 
		{
			Next(Prec) = Px;
		}
	}
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	//Kamus lokal
	address P = First(L);
	int Count = 0;
	//Algoritma lokal
	if(IsEmpty(L))
		return Count;
	else
	{
		do
		{
			Count++;
			P = Next(P);
		}while(P!= Nil);
		return Count;
	}
}
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke bawah dalam bentuk tabel */
/* Jika list kosong : menulis tidak ada highscore */
{
	//Kamus lokal
	address P = First(L);
	int i,countSpace1,countSpace2;
	//Algoritma lokal
	if (IsEmpty(L))
	{
		printf("Tidak ada data highscore");
	}else
	{
		printf("+-------------------------+-------+\n");
		printf("|Nama                     |Skor   |\n");
		printf("+-------------------------+-------+\n");
		do
		{
			printf("|%s",Info(P).name);
			for(i=0;Info(P).name[i]!='\0';++i);
			countSpace1 = 25 - i;
			for(i=0;i<countSpace1;i++)
				printf(" ");
			printf("|%d",Info(P).skor);
			countSpace2 = floor(log10(abs(Info(P).skor)))+1;
			countSpace2 = 7 - countSpace2;
			for(i=0;i<countSpace2;i++)
				printf(" ");
			printf("|\n");
			P = Next(P); //Next elemen
		}while (P!=Nil); //sudah tercapai elemen sebelum terakhir
		printf("+-------------------------+-------+\n");
	}
}

void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	//kamus lokal
	address P = Alokasi(X);
	
	//Algoritma lokal
	if (P != Nil)
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//Kamus lokal
	address P = First(*L) ;
	//Algoritma lokal
	(*X) = Info(P);
	First(*L)=Next(P);
	Dealokasi(&P);
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	//kamus lokal
	address P = Alokasi(X);
	//Algoritma lokal
	if (P != Nil)
	{
		InsertLast(L,P);
	}
}

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	Next(P)=First(*L);
	First(*L)=P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	Next(P)=Next(Prec);
	Next(Prec)=P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	//Kamus lokal
	address Px = First(*L);
	//Algoritma lokal
	if(IsEmpty(*L))
	{
		InsertFirst(L,P);
	}else
	{
		while (Next(Px)!=Nil)
			{
				Px = Next(Px); //Next Element
			}//udah sampai ujung
			InsertAfter(L,P,Px);
	}
}
/****************** TEST LIST KOSONG ******************/
bool IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	return(First(L)==Nil);
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	//Kamus lokal
	address P = (address) malloc (sizeof (ElmtList));
	//Algoritma lokal
	if (P == Nil) 
	{
		return (Nil);
	}else
	{
		Info(P)=X;
		Next(P)=Nil;
		return(P);
	}
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	//Kamus lokal
	//kosong
	//Algoritma lokal
	free(*P);
}