#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int stat_loc = 0;

	for (int i = 0; i < 3; ++i) {
		switch (fork())
		{
			case -1:
				perror("fork error");
				exit(1);
			case 0:
				// akcja dla procesu potomnego
				if(!execl(argv[1], argv[1], NULL)) {
					perror("execl error");
					exit(1);
				}

				break;
			default:
				// akcja dla procesu macierzystego
				if (wait(&stat_loc) == -1) {
					perror("wait error");
					exit(1);
				}

		}
	}
	
	printf("\nProces macierzysty:\n");
	if(!execl(argv[1], argv[1], NULL)) {
		perror("execl error");
		exit(1);
	}
}
