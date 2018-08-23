all:
	arm-linux-as   start.s -o start.o
	arm-linux-gcc -fno-builtin -c main.c -o main.o -I ./include
	arm-linux-gcc -fno-builtin -c tic.c -o tic.o -I ./include
	arm-linux-ld  -Ttext=70003000 start.o main.o tic.o   -o rtc
	arm-linux-objcopy -Ielf32-littlearm -O binary rtc rtc.bin
clean:
	rm -rf rtc rtc.bin *.o 
