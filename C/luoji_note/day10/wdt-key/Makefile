all:
	arm-linux-as   start.s -o start.o
	arm-linux-gcc -fno-builtin -c main.c -o main.o -I ./include
	arm-linux-ld  -Ttext=70003000 start.o main.o  -o wdt
	arm-linux-objcopy -Ielf32-littlearm -O binary wdt wdt.bin
clean:
	rm -rf wdt wdt.bin *.o
