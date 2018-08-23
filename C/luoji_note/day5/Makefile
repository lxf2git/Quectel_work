all:
	arm-none-linux-gnueabi-as swap.s -o swap.o
	arm-none-linux-gnueabi-ld -Ttext=70003000 swap.o -o swap
	arm-none-linux-gnueabi-objcopy -Ielf32-littlearm -O binary swap swap.bin
clean:
	rm -rf swap.o swap swap.bin
