all:
	arm-linux-gcc -fno-builtin -c main.c -o main.o -I ./include
	arm-linux-gcc -c  adc_init.c -o adc_init.o -I ./include
	arm-linux-gcc -c  adc_start.c -o adc_start.o -I ./include
	arm-linux-gcc -c  adc_end.c -o adc_end.o -I ./include
	arm-linux-gcc -c  adc_get.c -o adc_get.o -I ./include
	arm-linux-as  start.s -o start.o
	arm-linux-ld  start.o main.o adc_init.o adc_start.o adc_end.o adc_get.o  -o adc -Ttext=70003000
	arm-linux-objcopy  -Ielf32-littlearm -O binary adc adc.bin
clean:
	rm -rf main.o adc_init.o adc_start.o  adc_get.o start.o adc adc.bin
 
