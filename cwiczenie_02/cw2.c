#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int stat_loc = 0;

	execl(argv[1], argv[1], NULL);

	for (int i = 0; i < 3; ++i) {
		switch (fork())
		{
			case -1:
				perror("fork error");
				exit(1);
			case 0:
				// akcja dla procesu potomnego
				execl(argv[1], argv[1], NULL);

				break;
			default:
				// akcja dla procesu macierzystego
				if (wait(&stat_loc) == -1) {
					perror("wait error");
					exit(1);
				}

		}
	}
	return 0;
}
