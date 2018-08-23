/******************************************
 *45、删除一个字符串中#之间的所有数据(含#)
 如果为奇数个# 则最后一个#后的所有数据全部删除(含#)

 例如：abcd##sjj#jgo#jsab#iojw
 删除后为abcdsjjjsab

 *
*
 * ***************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  N  (100)
int input(char* s);
int delet(char* s);

/******主函数*********/

int main() 
{
 	char s[N];
	
	input(s);

	delet(s);

	 return 0; 
}
/****输入函数**********/

int input(char* s)
{
	printf("please input string\n"); 

	gets(s);
	 return 0; 
}

/*****删除函数********/

int delet(char* s)
{
	int i=0, j=0, k=0;

	char str[N];

	for (; i<strlen(s); i++)
	{
		if (s[i] != '#')
		{	
			str[j++] = s[i];
		
		}

		else 
		{
			for (k=i+1; k<strlen(s); k++)
			{				
					if (s[k] == '#')
						break;
			}
/****** 注意i = k 将i 跳到k小标处********/

			i=k;
		}					
	}
	
	str[j] = '\0';
	puts("string:");
	puts(str);
}















