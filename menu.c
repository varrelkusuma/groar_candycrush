// Main Menu
// Rifda 12 Nov 2017

#include <stdio.h>

int main() {
	int pil=0;
	do {
		
		printf("-------MENU-------\n");
		printf("1. Play\n");
		printf("2. How To Play\n");
		printf("3. About\n");
		printf("4. Quit\n");
		do {
			printf("Pilihan Anda: ");
			scanf("%d",&pil);
			if (pil<1 || pil>4) {
				printf("Input Salah!\nMasukkan Angka 1-4!\n");
			}
		} while (pil<1 || pil>4);

		//masuk ke menu pilihan doi
		switch (pil) {
			case (1): 
				printf("Masuk ke game ini\n");
				break;

			case (2):
				printf("Masuk ke How to Play\n");
				break;

			case (3):
				printf("Masuk ke About\n");	
				break;

			case (4):
				printf("Sampai Jumpa Lagi! bubaay\n");
		}
	}
	while (pil!=4);


	return 0;
}
