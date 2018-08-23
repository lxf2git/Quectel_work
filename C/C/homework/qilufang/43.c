#include<stdio.h>
#include<stdlib.h>
void new_str(char *p);
void Memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("Memory_error!");
		exit(-1);
	}
}
int main()
{
	int i;	
	char *ptr;
	Memory((void **)&ptr,30*sizeof(char));
	printf("输入一个字符串：\n");
	scanf("%s",ptr);
//	printf("%s\n",ptr);
/*	for(i=0;i<30;i++)
	{
		printf("%d",*(ptr+i));
	}	*/	
	printf("加#后输出：\n");	
	new_str(ptr);
	return 0;
}	
void new_str(char *p)
{
	int i,j,a=0;
	for(i=0;*(p+i)!='\0';i++)
	{	
		printf("%c",*(p+i));
		if(i==0)
		{
			printf("#");
		}
		if(i!=0)
		a++;
		for(j=2*a+1;j>0&&i!=0;j--)
		{
			printf("#");
		}
	}
	printf("\n");
}
