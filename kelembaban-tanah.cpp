#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int i;
int kelembapan = 40;
char *status;

void clearScreen() {
    system("cls");
}

void alat_aktif(){

	// Membersihkan layar konsol
    clearScreen();
	//Menyala
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
	// Membersihkan layar konsol
    clearScreen();
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
		if(kelembapan == 40){
			for(i = 40; i<=80; i+=2){	
				kelembapan = i;
				alat_aktif();
				sleep(1);
				status = "Keran Menyala";
			}
		if(kelembapan == 80){
			for(i = 80; i>=40; i-=2){
				kelembapan = i;
				alat_tidakaktif();
				sleep(1);
				status = "  Keran Mati ";
			}
		}
		kelembapan = 40;			
	}
	}
}
