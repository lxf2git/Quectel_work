#include <stdlib.h>
#include <stdio.h>
void show_err(char *str)//显示错误，并退出
{
		perror(str);
		exit(-1);
}
void set_err(int a,char b[50])
{
		if(a==-1)
		show_err(b);
}
