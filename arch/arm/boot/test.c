#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

#define __NR_process_status 375

int main() {
	int i, status;
	printf("\n\nHello World!\n\n");
	pid_t pid = fork();
	if (pid == -1) {
		perror("\n\nfork failed\n\n");
		return 1;
	} else
		while (1) {
		sleep(1);
			if (pid == 0) {	// Child
				getchar();
				for (i = 0; i < 10; i++)
					printf("%d ", i);
				printf("\n");
			} else {	// Parent
				status = syscall(__NR_process_status, pid);
				printf("\n\nStatus: %d\n\n", status);
			}
		}
	return 0;
}
