all:
	arm-linux-as   start.s -o start.o
	arm-linux-gcc -fno-builtin -c main.c -o main.o -I ./include
	arm-linux-ld  -Ttext=70003000 start.o main.o  -o mmu
	arm-linux-objcopy -Ielf32-littlearm -O binary mmu mmu.bin
clean:
	rm -rf mmu mmu.bin *.o
