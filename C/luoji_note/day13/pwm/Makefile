all:
	arm-linux-gcc   -c  main.c -o main.o -I ./include 
	arm-linux-as    start.s -o start.o
	arm-linux-ld start.o  main.o -o arm -Ttext=50003000 
	arm-linux-objcopy    -Ielf32-littlearm -O  binary  arm arm.bin
clean:
	rm -rf arm arm.bin start.o main.o driver.o 
