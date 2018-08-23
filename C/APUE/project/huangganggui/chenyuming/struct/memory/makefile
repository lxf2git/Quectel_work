TARGET=memory_manager 
SRC=list.c main.c memory.c  
#SRC=$(wildcard *.c)  
#OBJ=$(SRC:.c=.o)  
CFLAGS=-g -Wall -o  

$(TARGET):$(SRC)  
	gcc $(SRC) $(CFLAGS) $(TARGET)  
clean:  
	rm $(TARGET)
