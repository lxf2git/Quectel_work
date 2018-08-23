#include<stdio.h>
#include<string.h>
#define N 20
void cat(char a1[N],char a2[N],int j,int k);
void paixu(char str[N],int row);
void dele(char a[N],int b);
int main()
{
	int a=0,b=0,k;
	char str_1[N]={'\0'};
	char str_2[N]={'\0'};
	printf("输入字符串1：\n");
	gets(str_1);
	a=strlen(str_1);
	printf("排序输出字符串1：\n");
	paixu(str_1,a);
	printf("输入字符串2：\n");
	gets(str_2);
	b=strlen(str_2);
//	printf("a:%db:%d\n",a,b);
	printf("排序输出字符串2：\n");
	paixu(str_2,b);  
	cat(str_1,str_2,a,b);
	printf("最后排序输出合并字符串：\n");
	paixu(str_1,a+b);
	printf("去掉相同字母最后输出：\n");
	dele(str_1,a+b);
	return 0;

}
void paixu(char str[N],int row)
{
	int i=0,j,k;
	char a;
//	printf("row:%d\n",row);
//	puts(str);
	for(j=0;j<row;j++)
	{	
		for(i=0;i<row;i++)
		{
			a=str[i];
			if(a>str[i+1])
			{
				str[i]=str[i+1];
				str[i+1]=a;
			}
		}
	}	
	for(k=0;k<row+1;k++)
	{
		printf("%c",str[k]);
	}	
	printf("\n");   
}
void cat(char a1[N],char a2[N],int j,int k)
{
	int i,p=0,l;
	for(i=j;i<j+k+2;i++)
	{
		p++;
		a1[i+1]=a2[p];
	}
//	strcat(a1,a2);
//	printf("c:%d",c);
	printf("合并后输出：\n");
//		printf("%s",a1);
	for(l=0;l<j+k+1;l++)
	{
		printf("%c",a1[l]);
	}	
	printf("\n");   

}
void dele(char a[N],int b)
{
		int i,l,j;
		for(i=0;i<b;i++)
		{
				for(j=0;j<b;j++)
				{
						if(a[j]==a[j+1])
						{
								a[j]=a[j-1];
						}	
				}
		}
	for(l=0;l<=b;l++)
	{
		printf("%c",a[l]);
	}	
	printf("\n");
}
