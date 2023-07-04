#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <cmath>
#include <iostream>

#define TIME_FACTOR 5000000 // Faktor percepatan waktu

int i;
int kelembapan = 80;
char *status;
clock_t start_time = clock(); // Waktu awal simulasi

void clearScreen() {
	#if defined(__linux__)
		system("clear");
	#elif _WIN32
    	system("cls");
	#endif
}

void alat_aktif(){
	clock_t current_time = clock(); // Waktu saat ini
	double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;

	// Menghitung waktu yang dipercepat
	double accelerated_time = elapsed_time * TIME_FACTOR;

	// Mendapatkan informasi jam, menit, dan detik
	int hour = (int)accelerated_time / 3600;
	int minute = ((int)accelerated_time % 3600) / 60;
	int second = (int)accelerated_time % 60;

	// Menampilkan waktu dalam format jam:menit:detik
	if(hour >= 24){
		hour -= 24 * std::floor(hour / 24);
	}
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

void alat_tidakaktif(){
	clock_t current_time = clock(); // Waktu saat ini
	double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;

	// Menghitung waktu yang dipercepat
	double accelerated_time = elapsed_time * TIME_FACTOR;

	// Mendapatkan informasi jam, menit, dan detik
	int hour = (int)accelerated_time / 3600;
	int minute = ((int)accelerated_time % 3600) / 60;
	int second = (int)accelerated_time % 60;
	if(hour >= 24){
		hour -= 24 * std::floor(hour / 24);
	}
	// Menampilkan waktu dalam format jam:menit:detik
	if(hour == 7 || hour == 16){
		int placeholder = hour;
		for(i = kelembapan; i<=80; i+=30){	
			status = "Keran Menyala";
			if(i < 80){
				i += 20
			}
			kelembapan = i;
			alat_aktif();
			sleep(1);
			if(hour > placeholder + 1){
				break;
			}
		}
	}
	// Membersihkan layar konsol
    clearScreen();
	//Menyala
	printf("%02d:%02d:%02d      \n", hour, minute, second);
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

	while(true){
		clearScreen();
		// if(kelembapan == 40){
		// 	for(i = 40; i<=80; i+=2){	
		// 		status = "Keran Menyala";
		// 		kelembapan = i;
		// 		alat_aktif(start_time);
		// 		sleep(1);
		// 	}
		// }
		// if(kelembapan == 80){
		status = "  Keran Mati ";
		kelembapan -= 2;
		alat_tidakaktif();
		sleep(1);
		// }
	}
}
