all:
	arm-linux-gcc -fno-builtin  -c main.c -o main.o -I ./include
	arm-linux-gcc -fno-builtin  -c key_test.c -o key_test.o -I ./include
	arm-linux-gcc -fno-builtin  -c led_driver.c -o led_driver.o -I ./include
	arm-linux-as  start.s -o start.o
	arm-linux-ld  start.o main.o key_test.o led_driver.o -o key_led -Ttext=70003000
	arm-linux-objcopy  -Ielf32-littlearm -O binary key_led key_led.bin
clean:
	rm -rf mian.o key_test.o led_driver.o start.o key_led key_led.bin
