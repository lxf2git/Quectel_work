#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void change(char *str);
void output(char *str,char *p);

/********主函数****************/
int main()
{
		char str[20]="ABCD1234efgh";
		printf("调换前string：\n");
		printf("%s\n",str);
		change(str);
}

/**********排序函数*******************/
void change(char *str)
{
		int i,j=0,k;
		char *p=NULL;
		p=malloc(20*sizeof(char));	
		for(i=strlen(str)-1;i>=0;i--)		//倒续赋值给地址p
		{
				j++;
				*(p+j)=*(str+i);
		}
		output(str,p);
		free(p);
}

/************输出函数*******************/
void output(char *str,char *p)
{
		int i,k;
		for(i=0;i<20;i++)						//p地址内数据附给str
		{
				*(str+i)=*(p+i);
		}
		printf("调换后输出：\n");
		for(k=0;k<20;k++)
		{
				printf("%c",*(p+k));
		}
		printf("\n");
}

