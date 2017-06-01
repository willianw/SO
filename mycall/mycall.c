#include <linux/linkage.h>
#include <linux/kernel.h>

asmlinkage long sys_mycall(int i) {
	printk("Hello World grupo 4\n");
	return i + 1;
}
