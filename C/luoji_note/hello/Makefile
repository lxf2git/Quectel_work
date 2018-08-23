all:
	arm-none-linux-gnueabi-as swapcp.s -o swapcp.o
	arm-none-linux-gnueabi-ld -Ttext=70003000 swapcp.o -o swapcp
	arm-none-linux-gnueabi-objcopy -Ielf32-littlearm -O binary swapcp swapcp.bin
clean:
	rm -rf swapcp.o swapcp swapcp.bin
