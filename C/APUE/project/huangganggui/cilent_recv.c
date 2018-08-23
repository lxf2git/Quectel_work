#include "apue.h"
int Recv_send_friendCircle_recv(sData_package package,Socks Socks)
{
		printf("%s:",package.dest_user);
		printf("%s\n",package.dorinform.data);
		return 0;
}
