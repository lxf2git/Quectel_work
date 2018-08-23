/*******************************************************************************************************************************
 *
 * 作业29 
 *输出 word line character
 *
 *
 *																		创建人：邢宏彬		
 *                                                                     创建时间 2015年8月6日19时09分04秒
 * *****************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int input_line(char a[][100]);
int str_space(char a[][100],int line);
int str_length(char a[][100],int line);
int main()
{
		int i=0,j;
		int character,word,line;
		int length,space;

		char a[100][100];

		line=input_line(a);
		space=str_space(a,line);
		length=str_length(a,line);

		character=length-1-space;                          //字符数等于 总字符长度 去掉空格 回车 重第二行开始getchar 会吃掉一个
		word=line+space;
		printf("space%d line%d length%d\n",space,line,length);
		printf("character:%d word:%d line:%d\n",character,word,line);
		return 0;
}

int input_line(char a[][100])
/*********输入字符 并返回列数**********/   
{
		int i,j;
		for(j=0;;j++)
		{
				for(i=0;;i++)
				{
						scanf("%c",&a[j][i]);
						if(a[j][i]=='\n')
								break;
	
				}
				a[j][i+1]='\0';
				if(getchar()=='\n')                             //如果 不是回车会吃掉一个字符
						break;
		}
		return j+1;
}

int str_space(char a[][100],int line)
/*********字符 空格数**********/   
{
		int i,j;
		int space=0;
		for(i=0;i<line;i++)
		{
				for(j=0;a[i][j]!='\0';j++)
						if(a[i][j]==' ')
								space++;
		}
		return space;


}
int str_length(char a[][100],int line)
/*********字符 总字符**********/   
{
		int i,j;
		int length=0;
		for(i=0;i<line;i++)
		{
				length+=strlen(a[i]);
		}
		return length;
						
}
