all:
	arm-none-linux-gnueabi-gcc -fno-builtin -c strlen.c -o strlen.o 		
	arm-none-linux-gnueabi-ld -Ttext=50003000 strlen.o -o strlen
	arm-none-linux-gnueabi-objcopy -Ielf32-littlearm -O binary strlen strlen.bin
clean:
	rm -rf strlen.o strlen strlen.bin
