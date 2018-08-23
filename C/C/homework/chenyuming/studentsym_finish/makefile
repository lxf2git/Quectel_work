exe : main.o function.o inoutput.o interface.o quit.o search.o del.o \
		init.o insert.o print.o save.o
		cc -o exe main.o function.o inoutput.o interface.o  \
			quit.o search.o del.o init.o insert.o print.o save.o

main.o : main.c stusys.h
		cc -c main.c

function.o : function.c stusys.h
		cc -c function.c

inoutput.o : inoutput.c stusys.h
		cc -c inoutput.c

interface.o : interface.c stusys.h
		cc -c interface.c

quit.o : quit.c stusys.h
		cc -c quit.c

search.o : search.c stusys.h
		cc -c search.c

del.o : del.c stusys.h
		cc -c del.c

init.o : init.c stusys.h
		cc -c init.c

insert.o : insert.c stusys.h
		cc -c insert.c

print.o : print.c stusys.h
		cc -c print.c

save.o : save.c stusys.h
		cc -c save.c


clear : 
	rm -f *.o exe
