#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
void deal(char *ptr,int len);
/*********创建空间函数****************/

void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
/*********主函数************************/

int main()
{
	char *str;
	printf("please input a string with '#':\n");
	getmemory((void **)&str,N*sizeof(char));
	gets(str);
	deal(str,strlen(str));
	if(str != NULL)
	{
		free(str);
		str=NULL;
	}
	return 0;

}
/***********执行函数*****************/

void deal(char *ptr,int len)
{
	int i,j=0,k;
	char *str_1;
	getmemory((void **)&str_1,N*sizeof(char));
	for(i=0;i<len;i++)
	{
		if(*(ptr+i) != '#')				//当*（ptr+i）不是#时赋值给新空间
										//		*（str——1）
		{
			*(str_1+j)=*(ptr+i);
			j++;
		}
		else 							//当字母是‘#’时去除
		{
			k=i+1;
			do
			{
				k++;
			}while(*(ptr+k)!='#'&&k<strlen(ptr));
			i=k;
		}
	}
	*(str_1+j)='\0';
	printf("去除两个'#'之间部分最后得：\n");
	puts(str_1);
	if(str_1 != NULL)
	{
		free(str_1);
		str_1=NULL;
	}
}
