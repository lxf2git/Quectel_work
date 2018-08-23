all:
	arm-none-linux-gnueabi-as beep.s -o beep.o
	arm-none-linux-gnueabi-ld -Ttext=70003000 beep.o -o beep
	arm-none-linux-gnueabi-objcopy -Ielf32-littlearm -O binary beep beep.bin
clean:
	rm -rf beep.o beep beep.bin
