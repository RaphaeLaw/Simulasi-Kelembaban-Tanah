#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

#define TIME_FACTOR 10 // Faktor percepatan waktu

int i;
int kelembapan = 40;
char *status;
clock_t current_time = clock(); // Waktu saat ini	

void clearScreen() {
	#if defined(__linux__)
		system("clear");
	#elif _WIN32
    	system("cls");
	#endif
}

void alat_aktif(clock_t start_time){
	clock_t current_time = clock(); // Waktu saat ini
	double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC * 10000;

	// Menghitung waktu yang dipercepat
	double accelerated_time = elapsed_time * TIME_FACTOR;

	// Mendapatkan informasi jam, menit, dan detik
	int hour = (int)accelerated_time / 3600;
	int minute = ((int)accelerated_time % 3600) / 60;
	int second = (int)accelerated_time % 60;

	// Menampilkan waktu dalam format jam:menit:detik

	// Membersihkan layar konsol
    clearScreen();
	//Menyala
	printf("%02d:%02d:%02d     _ \n", hour, minute, second);
	printf("           _|_|_ \n");
	printf("         _|_| |_|_  \n");
	printf("       _|_|     |_|_ \n");
	printf("     _|_|    _    |_|_ \n");
	printf("   _|_|    _|_|_    |_|_ \n");
	printf("  |_|_    |_|_|_|    _|_| \n");
	printf("    |_|_    |_|    _|_| \n");
	printf("      |_|_       _|_| \n");
	printf("        |_|_   _|_|            ____ \n");
	printf("          |_|_|_|             |_  _| \n");
	printf("            |_|             ____||_____ \n");
	printf("      \\     | |       * ***||________  \\ \n");
	printf("       \\____| |      * * *           |  | \n");
	printf("            | |___/ * *              |  | \n");
	printf("            | |    * **              |  | \n");
	printf("   _________|_|___*_***_             |  | \n");
	printf("  |    %s    |            |  | \n", status);
	printf("   \\_                 _/             |  | \n");
	printf("     |               |               |  | \n");
	printf("     |      %2d%%      |               |  | \n", kelembapan);
	printf("     |               |               |  | \n");
	printf("     |               |              _|  |_ \n");
	printf("      \\_____________/              |______| \n");
}

void alat_tidakaktif(clock_t start_time){
	clock_t current_time = clock(); // Waktu saat ini
	double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC * 10000;

	// Menghitung waktu yang dipercepat
	double accelerated_time = elapsed_time * TIME_FACTOR;

	// Mendapatkan informasi jam, menit, dan detik
	int hour = (int)accelerated_time / 3600;
	int minute = ((int)accelerated_time % 3600) / 60;
	int second = (int)accelerated_time % 60;

	// Menampilkan waktu dalam format jam:menit:detik

	// Membersihkan layar konsol
    clearScreen();
	//Menyala
	printf("%02d:%02d:%02d     _ \n", hour, minute, second);
	//Tidak Menyala
	printf("             _ \n");
	printf("           _|_|_ \n");
	printf("         _|_| |_|_  \n");
	printf("       _|_|     |_|_ \n");
	printf("     _|_|    _    |_|_ \n");
	printf("   _|_|    _|_|_    |_|_ \n");
	printf("  |_|_    |_|_|_|    _|_| \n");
	printf("    |_|_    |_|    _|_| \n");
	printf("      |_|_       _|_| \n");
	printf("        |_|_   _|_|            ____ \n");
	printf("          |_|_|_|             |_  _| \n");
	printf("            |_|             ____||_____ \n");
	printf("      \\     | |            ||________  \\ \n");
	printf("       \\____| |                      |  | \n");
	printf("            | |___/                  |  | \n");
	printf("            | |                      |  | \n");
	printf("   _________|_|_________             |  | \n");
	printf("  |    %s    |            |  | \n", status);
	printf("   \\_                 _/             |  | \n");
	printf("     |               |               |  | \n");
	printf("     |      %2d%%      |               |  | \n", kelembapan);
	printf("     |               |               |  | \n");
	printf("     |               |              _|  |_ \n");
	printf("      \\_____________/              |______| \n");	
}
int main (){
	clock_t start_time = clock(); // Waktu awal simulasi

	while(true){
		clearScreen();
		if(kelembapan == 40){
			for(i = 40; i<=80; i+=2){	
				status = "Keran Menyala";
				kelembapan = i;
				alat_aktif(start_time);
				sleep(1);
			}
		if(kelembapan == 80){
			for(i = 80; i>=40; i-=2){
				status = "  Keran Mati ";
				kelembapan = i;
				alat_tidakaktif(start_time);
				sleep(1);
			}
		}
		kelembapan = 40;			
	}
	}
}
