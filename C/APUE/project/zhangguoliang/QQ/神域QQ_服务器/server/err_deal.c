#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
void show_err(char *p)
{
		perror(p);
		exit(-1);
}
void set_err(int a,char *p)
{
		if(a<0)
		{
				show_err(p);
		}
}
