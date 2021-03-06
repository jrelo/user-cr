/*
 *  self_restart.c: demonstrate self-restart
 *
 *  Copyright (C) 2008 Oren Laadan
 *
 *  This file is subject to the terms and conditions of the GNU General Public
 *  License.  See the file COPYING in the main directory of the Linux
 *  distribution for more details.
 */

#define _GNU_SOURCE        /* or _BSD_SOURCE or _SVID_SOURCE */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <asm/unistd.h>
#include <sys/syscall.h>

#include <linux/checkpoint.h>

inline static int restart(pid_t pid, int fd, unsigned long flags)
{
	return syscall(__NR_restart, pid, fd, flags, CHECKPOINT_FD_NONE);
}

int main(int argc, char *argv[])
{
	pid_t pid = getpid();
	int ret;

	ret = restart(pid, STDIN_FILENO, RESTART_TASKSELF);
	if (ret < 0)
		perror("restart");

	printf("should not reach here !\n");

	return 0;
}
