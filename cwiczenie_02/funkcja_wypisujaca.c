#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Autor: Bartosz Satola
// Rozwiazania zadan z przemiotu Systemy Operacyjne na 27.03.2024
// Szczegoly w pliku README.md

int main()
{
	uid_t UID = getuid();
	gid_t GID = getgid();
	pid_t PID = getpid();
	pid_t PPID = getppid();
	pid_t PGID = getpgrp();

	printf("UID: %d / GID: %d / PID: %d / PPID: %d / PGID: %d\n",
			UID, GID, PID, PPID, PGID);

	return 0;
}
