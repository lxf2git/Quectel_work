#include<stdio.h>
int main()
{
		char *buf[1024];
		fprintf("%s\n", getcwd( buf,sizeof(buf) ) );
		return 0;
}
