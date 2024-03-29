#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	uid_t UID = getuid();
	gid_t GID = getgid();
	pid_t PID = getpid();
	pid_t PPID = getppid();
	pid_t PGID = getpgrp();

	printf("\nUID: %d / GID: %d / PID: %d / PPID: %d / PGID: %d\n\n",
			UID, GID, PID, PPID, PGID);

	return 0;
}
