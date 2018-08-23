all:
	arm-linux-as   start.s -o start.o
	arm-linux-gcc -fno-builtin -c main.c -o main.o -I ./include
	arm-linux-gcc -fno-builtin -c uart.c -o uart.o -I ./include
	arm-linux-ld  -Ttext=70003000 start.o main.o uart.o  -o uart
	arm-linux-objcopy -Ielf32-littlearm -O binary uart uart.bin
clean:
	rm -rf uart uart.bin *.o
