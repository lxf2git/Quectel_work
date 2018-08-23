#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void create_memory(void ** ptr,int size)
{
	*ptr = malloc(size);
	if(NULL == *ptr)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}


void deal(char *pa, char *pb,int m, int len)
{
	int i,j=0;
	for(i=0;i<len;i++)
	{
			if(i>0)
			{
				if((1+i)%4 == 0)
				{
					pa[i]=' ';
				}
				else
				{
					pa[i]=pb[j];
					j++;
				}
			}
			else
			{
				pa[i]=pb[j];
				j++;
			}
		
	}
	puts(pa);
}

int main()
{
	char str_old[1024];
	char * str_new;
	int len=0,m=0;
	printf("please input the old strings:");
	gets(str_old);
	puts(str_old);

	m = strlen(str_old);
	printf("m:%d\n",m);
	if(m%3 == 0)
	{
		len = m+(m/3-1);
	}
	else
	{
		len = m+m/3;
	}
	create_memory((void **)&str_new, len);
	printf("len:%d\n",len);
//	str_new = str_old;
//	puts(str_new);

	deal(str_new, str_old, m, len);
	return 0;
}
