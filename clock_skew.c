#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char** argv) {
	int rc;
	struct timeval adj, old;

	if (argc > 1 && strcmp(argv[1], "plus") == 0) {
		printf("skewing positive\n");
		adj.tv_sec = 2;
		adj.tv_usec = 0;
		rc = adjtime(&adj, &old);
	} else if (argc > 1 && strcmp(argv[1], "minus") == 0) {
		printf("skewing negative\n");
		adj.tv_sec = -2;
		adj.tv_usec = 0;
		rc = adjtime(&adj, &old);
	} else {
		printf("querying status\n");
		rc = adjtime(NULL, &old);
	}

	if (rc == 0) {
		printf("adjtime returned = %ld.%06u\n", old.tv_sec, old.tv_usec);
	} else {
		printf("adjtime failed: (%d) %s\n", errno, strerror(errno));
		return -1;
	}
	return 0;
}

