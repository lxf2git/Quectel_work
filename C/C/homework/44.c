/*****************************************
 *44、将字符串a的所有字符传送到字符串b中 每传3个字符 放一个空格

 例如：字符串a为"abcdefg" 则字符串b为"adc def g"

 要求：char str_old[1024];//存放输入数据

 char *str_new //根据输入的数据计算插入空格后的字符串长度开辟空间

 * ****************************************/
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define  N  (1024)

   
int input(char* s);
int count_len(char *s);
void creat_momery(void** p, int size);
int deal_str(char*a,char*b);
int new_n;  
/*******主函数********/

int main() 
{
	char str_old[N];
	char* str_new ;

	input(str_old);
	
	new_n = count_len(str_old);

	creat_momery((void**)&str_new, new_n*sizeof(*str_new));
						 
	deal_str(str_old, str_new);

	free(str_new);

	 return 0; 
}

/*******字符串输入*********/

int input(char* s)
{
	printf("please input a_string\n");
   	
	gets(s);	
	
	return 0; 
}

/******计算b字符串的空间大小****/

int count_len(char *s)
{
	int n=0;
	
	n = (strlen(s)/3) + strlen(s)+1;//注意要加1


	return n; 
}
/*****开辟空间*********************/

void creat_momery(void** p, int size)
{

		*p = malloc(size);
		if (NULL == *p)
		{
			printf("malloc error \n"); 
			exit(-1);
		}
}

/*******字符串a插入空格*********/

int deal_str(char*a,char*b)
{

/******b字符串全部赋值空格*******/

		int i=0, j=0, count =0;

		for (; i<new_n-1; i++) //开辟空间b 不确定里面有没有‘\0’ 所以不可以 用strlen();
		{
			*(b+i) = ' ';
		
		}

/******count 进行计数 每3次清零 将a[j]的值赋值给b*/

		for (i=0,j=0; i<new_n -1; i++)
		{

				if (count != 3)
				{	*(b+i) = *(a+j); //可以 写成 *(b+i) = *（a+j++）; //b[i] = a[j++]
						j++;
						count++;
				}
				else
						count = 0;
		}

		*(b+i) = '\0';

		puts("output b:");
		puts(b);
		return 0; 
}

























































