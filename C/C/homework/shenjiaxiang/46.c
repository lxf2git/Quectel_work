#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	int i,n,n1,n2;
	printf("input zifu\n");
	for(i=0;;i++)
	{	
		scanf("%c",(str_old+i));
		if(*(str_old+i)=='\n')
		{
			*(str_old+i)='\0'; //i-1-0+1=i
			break;
		} //最大下标是i，数组长度是i+1,str_old[i]='\0',除去'\0'共有i个字符
			//最后不为0的字符str_old[i-1];
	}
	printf("输入右移位数n\n");	
	scanf("%d",&n);//从右侧第n个操作，第n个下标为(i-1)-n+1//地址i-n+1+1
	n1=i-1-n+1;//	n2=i-n;//左侧剩余i-n个
	get_memory((void **)&str_new,(i+1)*sizeof(char));
	strncpy(str_new,str_old+n1,n);
	strncpy(str_new+n,str_old,n1);
	*(str_new+i+1)='\0';
	//printf("%d",j);//每给str_new赋值，j就指向下一个下标。循环结束后，j指向字符串的下一位
	puts(str_new);
}
