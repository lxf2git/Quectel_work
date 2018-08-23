all:
	arm-linux-gcc -fno-builtin -c key.c -o key.o
	arm-linux-ld -Ttext=70003000 key.o -o key
	arm-linux-objcopy -Ielf32-littlearm -O binary key key.bin

clean:
	rm -rf key.o key key.bin
