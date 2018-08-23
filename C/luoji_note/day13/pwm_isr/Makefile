all:
	arm-linux-as   start.s -o start.o
	arm-linux-gcc -fno-builtin -c main.c -o main.o -I ./include
	arm-linux-gcc -fno-builtin -c pwm.c -o pwm.o -I ./include
	arm-linux-ld  -Ttext=70003000 start.o main.o pwm.o   -o arm
	arm-linux-objcopy -Ielf32-littlearm -O binary arm arm.bin
clean:
	rm -rf arm arm.bin *.o 
