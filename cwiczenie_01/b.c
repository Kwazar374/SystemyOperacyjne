#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int stat_loc = 0;
	
	uid_t UID = getuid();
	gid_t GID = getgid();
	pid_t PID = getpid();
	pid_t PPID = getppid();
	pid_t PGID = getpgrp();
	
	printf("proces macierzysty:\n");
	printf("UID: %d / GID: %d / PID: %d / PPID: %d / PGID: %d\n\n",
			UID, GID, PID, PPID, PGID);

	printf("procesy potomne:\n");

	for (int i = 0; i < 3; ++i) {
		switch (fork())
		{
			case -1:
				perror("fork error");
				exit(1);
			case 0:
				// akcja dla procesu potomnego
				UID = getuid();
				GID = getgid();
				PID = getpid();
				PPID = getppid();
				PGID = getpgrp();

				printf("(%d) / UID: %d / GID: %d / PID: %d / PPID: %d / PGID: %d\n",
				i, UID, GID, PID, PPID, PGID);
				break;
			default:
				// akcja dla procesu macierzystego
				if(wait(&stat_loc) == -1) {
					perror("wait error");
					exit(1);
				}

		}
	}
	return 0;
}
