objects = ser_deal_process.o ser_cmd_ls.o ser_cmd_cd.o ser_cmd_put.o \
		  ser_cmd_get.o ser_cmd_mkdir.o ser_cmd_pwd.o ser_cmd_quit.o \
		  ser_deal_cmd.o server.o ser_deal_list.o

ftp-server: $(objects)
			gcc -Wall -o  ftp-server $(objects) -lcrypt

clean:
	rm ftp-server $(objects)
