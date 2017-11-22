// Main Menu
// Rifda 12 Nov 2017

#include <stdio.h>

void menu_about() {
	printf("-------ABOUT-------\n");
	printf("Game ini terinspirasi dari game Candy Crush Saga.\nGame ini dibuat dalam rangka Tugas Besar Matakuliah Algoritma dan Struktur Data, 2017\n");
}

void menu() {
	char conf_exit;
	int pil=0;
	printf("-------MENU-------\n");
	printf("1. Play\n");
	printf("2. How To Play\n");
	printf("3. Highscore\n");
	printf("4. About\n");
	printf("5. Quit\n");

	do {
		printf("Pilihan Anda: ");
		scanf("%d",&pil);
		if (pil<1 || pil>5) {
			printf("Input Salah!\nMasukkan Angka 1-5!\n");
		}
	} while (pil<1 || pil>5);

	//masuk ke menu pilihan doi
	switch (pil) {
		case (1): 
			printf("Masuk ke game ini\n");
			menu();
			break;

		case (2):
			printf("Masuk ke How to Play\n");
			menu();
			break;

		case (3):
			printf("Masuk ke highscore\n");	
			
			menu();
			break;

		case (4):
			menu_about();
			menu();
			break;

		case (5):
			do{
				printf("Kamu yakin mau keluar? (Y/N)\n");
				scanf(" %c",&conf_exit);
				if (conf_exit=='N'|| conf_exit=='n') {
					menu();
					break;
				} else if (conf_exit=='Y'|| conf_exit=='y'){
					printf("BYE!\n");
				} else
				printf("Input Salah!\n");
			} while (conf_exit!='N' && conf_exit!='Y' && conf_exit!='y' && conf_exit!='n');
			break;
	}
}


int main() {
	menu();
	return 0;
}
