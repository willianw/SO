make ARCH=arm CROSS_COMPILE=arm-none-eabi- all
cd arch/arm/boot
arm-none-linux-gnueabi-gcc -static test.c -o test
echo test | cpio -o --format=newc > rootfs
qemu-system-arm -M  versatilepb -m 128M -kernel zImage -initrd rootfs -append "root=/dev/ram rdinit=/test"
