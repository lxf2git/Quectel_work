#include<stdio.h>
#include<string.h>
int main()
{
		char string1[100]={'\0'};
		char string2[100]={'\0'};
		printf("输入字符串1\n");
		gets(string1);
		//puts(string1);
		printf("输入字符串2\n");
		gets(string2);
		char t;
		int i,j,N;
		N=strlen(string1);
		for(i=0;i<N;i++)
		{
				for(j=0;j<(N-1-i);j++)
				{
						if(string1[j]>string1[j+1])
						{
								t=string1[j];
								string1[j]=string1[j+1];
								string1[j+1]=t;
						
						}
				}
		}
		N=strlen(string2);
		for(i=0;i<N;i++)
		{
				for(j=0;j<(N-1-i);j++)
				{
						if(string2[j]>string2[j+1])
						{
								t=string2[j];
								string2[j]=string2[j+1];
								string2[j+1]=t;
							
						}
				}
		}
		strcat(string1,string2);
		N=strlen(string1);
		for(i=0;i<N;i++)
		{
				for(j=0;j<(N-1-i);j++)
				{
						if(string1[j]>string1[j+1])
						{
								t=string1[j];
								string1[j]=string1[j+1];
								string1[j+1]=t;
						}
				}
		}
		printf("输出排序好的\n");
		puts(string1);
		for(i=0;i<N;i++)
		{
		for(j=0;j<N;j++)
		{
						if(string1[j]==string1[j+1])
						{
								string1[j+1]=string1[j+2];
						}
				
		}
		}
		printf("输出去重的\n");
		puts(string1);
		return 0;
}
