#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

#define __NR_mycall 374

void main() {
	printf("\n\nHello World!\n\n");
	while(1) {
		getchar();
		if (syscall(__NR_mycall, 2) == -1)
			break;
		printf("Imprimiu!\n");
	}
}
