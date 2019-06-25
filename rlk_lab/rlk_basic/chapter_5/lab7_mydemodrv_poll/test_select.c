#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ret;
	int fds[2];
	fd_set rfds;
	char buffer0[64];
	char buffer1[64];

	fds[0] = open("/dev/mydemo0", O_RDWR);
	if (fds[0] == -1) 
		goto fail;

	fds[1] = open("/dev/mydemo1", O_RDWR);
	if (fds[1] == -1) 
		goto fail;

	while (1) {
		FD_ZERO(&rfds);
		FD_SET(fds[0], &rfds);
		FD_SET(fds[1], &rfds);

		ret = select(fds[1]+1, &rfds, NULL, NULL, NULL);
		if (ret == -1)
			goto fail;

		if (FD_ISSET(fds[0], &rfds)) {
			ret = read(fds[0], buffer0, sizeof(buffer0));
			if (ret < 0)
				goto fail;
			printf("Read %s from /dev/mydemo0\n", buffer0);
		}

		if (FD_ISSET(fds[1], &rfds)) {
			ret = read(fds[1], buffer1, sizeof(buffer1));
			if (ret < 0)
				goto fail;

			printf("Read %s from /dev/mydemo1\n", buffer1);
		}
	}

fail:
	perror("select test failed");
	exit(EXIT_FAILURE);
}
