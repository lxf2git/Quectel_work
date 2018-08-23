#include<stdio.h>
#include<stdlib.h>

void get_memory(void **p,int size)
{
	*p=(void *)malloc(size);
	if(NULL==p)
	{
		printf("p:error");
		exit(-1);
	}
}

int main()
{
	char str_old[1024];
	char *str_new;
	int i,j,n;
	printf("input zifu\n");
	for(i=0;;i++)
	{	
		scanf("%c",(str_old+i));
		if(*(str_old+i)=='\n')
		{
			*(str_old+i)='\0'; //最大下标是i，数组长度是i+1
			break;
		} //最大下标是i，数组长度是i+1,出去'\0'共有i个字符
	}
	printf("%d \n",i);	
	j=i/3*4+i%3+1;
	get_memory((void **)&str_new,j*sizeof(char));
	printf("%d \n",j);
	for(j=0,n=0;n<i+1;)
	{
	
		if((n%3!=0)||(n==0))
		{
			*(str_new+j)=*(str_old+n);
			j++;
			n++;
		}
		else
		{
			*(str_new+j)=' ';
			j++;
			*(str_new+j)=*(str_old+n);
			j++;
			n++;
		}
	}
	//printf("%d",j);//每给str_new赋值，j就指向下一个下标。循环结束后，j指向字符串的下一位
	*(str_new+j)='\0';
	puts(str_new);
}
