all:
	arm-linux-as   start.s -o start.o
	arm-linux-gcc -fno-builtin -c main.c -o main.o -I ./include
	arm-linux-ld  -Ttext=70003000 start.o main.o  -o eint
	arm-linux-objcopy -Ielf32-littlearm -O binary eint eint.bin
clean:
	rm -rf eint eint.bin *.o
