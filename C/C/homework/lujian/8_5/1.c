/****************************************
 *1	统计文章的 字符数（不报括空格字符 ‘\0’, '\n'）

  2 统计 文章的 单词数

  3 统计 行数 

 								2015 08 05：
										陆剑
 * ****************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define  N  (100)
//#define  M  (100)
int n;
int input(char str[][N]);
int count_ch(char str[][N],int space);
int count_word(char str[][N]);
int count_str_word(char str[]);
int main()
{
	int re_ch, i,re_word, re_line, re_space;
/*	printf("please you plan input n line\n"); 
	scanf("%d",&n);
	getchar();
	*/
	char str[N][N] = {};

#if 0
	printf("please input\n"); 
	for (i = 0;i<N; i++)
	{
		gets(str[i]);
	 
	}
#endif 
//	re_line =
		   	input(str);
	re_space = count_space(str);
	re_ch = count_ch(str,re_space);
	re_word = count_word(str);
	re_line  = count_line(str);
	printf("re_ch = %d\nre_word=%d\nre_line =%d",
					re_ch, re_word, re_line); 

		return 0; 

	
}

/****************输入字符串组************/

int input(char str[][N])
{
	int i;
	printf("please input\n"); 
	for (i = 0;; i++)
	{
	//	printf("[%s = %d line]%p\n", __FUNCTION__, __LINE__ ,str[0]); 
		gets(str[i]);
//	
//
//	printf("str[%d]=%d\n",i,strlen(str[i])); 

/**********输入结束****************/

	 	if (0==strlen(str[i]))
				break;
	}
	return i; 
}
 
/**********统计字符多少************/

int count_ch(char str[][N],int space)
{	int i;
	int sum_ch = 0;
	for (i=0; i<N; i++)
	{
		sum_ch += strlen(str[i]);
	}
	
		sum_ch = sum_ch -space;
		return sum_ch;
}
/*************统计字符串组的word的个数*********/

int count_word(char str[][N])
{
	int i, sum_word = 0;

	for (i = 0; i<N; i++)
	{
			sum_word += count_str_word(str[i]);
	}

		return sum_word;
}
/************统计字符串的word的个数*********/

int count_str_word(char str[])
{
		int i, flag=0, num = 0;

		for (i = 0; str[i] !='\0'; i++)
		{
			if (str[i] == ' ')
					flag = 0;
		
			else if(flag == 0)
			{
					flag =1;
					num++;
			}		 
			
		}

		return num;

}

/***************计算空格数****************/

int count_space(char str[][N])
{
	int i, j, space= 0;
	for (i =0; i<N; i++ )
	{
		for (j=0;str[i][j]!='\0'; j++)
		{
			if (str[i][j] == ' ')
			{
				space++;
			}
		
		}	
		
	}
	printf("space =%d\n",space); 

	return space; 
}

/***********计算行数****************/

int count_line(char a[][N])
{
	int i, j, flag = 0, num =0; 

	for (i = 0 ; i<N ; i++)
	{
			flag = 0;
		for (j = 0; j<=strlen(a[i]); j++)
		{
			if (a[i][j] != '\0')

					flag=1;

			else if (1==flag)
			{
				flag =0 ;
				num++;
				printf("num=  %d\n",num); 
						
			}
		
		}
	}
	
	return num;
	
}










