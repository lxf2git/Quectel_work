#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
int main() 
{
		char str_old[1024];
		char *str_new;//根据输入的数据计算插入空格后的字符串长度开辟空间
		scanf("%s",str_old);
		int i,j;
		int x = (strlen(str_old)*4)/3;//要开辟的空间
		str_new = (char *)malloc(x*sizeof(char));
		for(i=0,j=0;i<strlen(str_old);i++,j++)
		{
				if(j%4==3)//这里是j每四个一次循环，而每到三的后一位是空格
				{
					*(str_new+j)=' ';
					i--;	
				}
				else
				{
					*(str_new+j)=str_old[i];
				}
				printf("%c",*(str_new+j));
		}
		if(str_new!=NULL)
		{
				free(str_new);
		}
		return 0;
		
}
