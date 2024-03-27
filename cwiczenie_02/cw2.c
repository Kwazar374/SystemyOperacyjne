#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

// Autor: Bartosz Satola
// Rozwiazania zadan z przedmiotu Systemy Operacyjne na 27.03.2024
//
// Program tworzy procesy potomne i dla kazdego z nich zastępuje jego obraz
// Obrazem nowego procesu będącego wywolaniem pliku wykonywalnego funkcja_wypisujaca.x
//
// Kod zrodlowy wyzej wymienionego pliku znajduje sie w pliku funkcja_wypisujaca.c
// Szegoly dotyczace tresci zadania i uruchomienia znajduja sie w pliku README.md

int main(int argc, char *argv[]) {

	// Sprawdzenie, czy sposob uruchomienia programu jest poprawny
	if(argc != 2) {
		perror("niepoprawna liczba argumentow wywolania programu");
		exit(1);
	}

	// Zmienna potrzebna przy obsludze bledow funkcji wait
	int stat_loc = 0;

	// Przygotowanie argumentu wywolania funkcji execlp
	char execArg0[200];
	strcpy(execArg0, "./");
	strcat(execArg0, argv[1]);
	
	for (int i = 0; i < 3; ++i) {
		switch (fork())
		{
			case -1:
				perror("fork error");
				exit(1);
			case 0:
				// Akcja dla procesu potomnego
				if(!execlp(execArg0, argv[1], NULL)) {
					perror("execlp error");
					exit(1);
				}

				break;
			default:
				// Akcja dla procesu macierzystego
				if (wait(&stat_loc) == -1) {
					perror("wait error");
					exit(1);
				}

		}
	}
	
	// Akcja dla procesu macierzystego
	printf("\nProces macierzysty:\n");
	if(!execlp(execArg0, argv[1], NULL)) {
		perror("execlp error");
		exit(1);
	}
	
	return 0;

}
