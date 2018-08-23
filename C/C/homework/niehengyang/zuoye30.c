#include<stdio.h>
#include<string.h>
int str1(char ch1[],int j);
int str2(char ch2[],int k);
int add(char ch1[],char ch2[]);
int change(char ch1[]);
int delete(char ch1[]);
char ch1[100];
char ch2[100];
int j,k;

int main()
{
	printf("please input str1:");
	gets(ch1);
	j=strlen(ch1);
	 str1(ch1,j);
	printf("please input str2:");
	gets(ch2);
	k=strlen(ch2);
	 str2(ch2,k);
	printf("\n");
	 add(ch1,ch2);
	printf("\n");
	change(ch1);
	printf("\n");
	delete(ch1);
}
int str1(char ch1[],int j)
{
	int i,m;
	char l;
	for(m=0;m<j;m++)
	{
		for(i=0;i<j;i++)
		{
			l=ch1[i];
			if(l>ch1[i+1])
			{
				ch1[i]=ch1[i+1];
				ch1[i+1]=l;

			}
		}

	}
	printf("对str1排序:\n");
	for(i=0;i<j+1;i++)
	{
	printf("%c",ch1[i]);
	}
	printf("\n");
}
int str2(char ch2[],int k)
{
	int i,n;
	char t;
	for(n=0;n<k;n++)
	{
		for(i=0;i<k;i++)
		{
			t=ch2[i];
			if(t>ch2[i+1])
			{

				ch2[i]=ch2[i+1];
				ch2[i+1]=t;

			}


		}

	}

	printf("对str2排序:\n");
	for(i=0;i<k+1;i++)
	{
	printf("%c",ch2[i]);
	}
}	
int add(char ch1[],char ch2[])
{
	int i,p=0;
	for(i=j;i<j+k+2;i++)
	{
		p=p+1;
		ch1[i+1]=ch2[p];
	}
	
/*	int i;
	strcat(ch1,ch2);
*/	printf("合并str1,str2后:\n");
	for(i=0;i<j+k+1;i++)
	{
	printf("%c",ch1[i]);
	}
	printf("\n");
}
int change (char ch1[])
{
	int i,g,u;
	
	for(u=0;u<j+k+2;u++)
	{
		for(i=0;i<j+k+2;i++)
		{
			g=ch1[i];
			if(g>ch1[i+1])
			{
				ch1[i]=ch1[i+1];
				ch1[i+1]=g;
			}
		}
	}
	printf("对合并后的字符串进行排序:\n");
	for(i=0;i<j+k+3;i++)
	{
		printf("%c",ch1[i]);
	}
	printf("\n");
}
int delete(char ch1[])
{
	int i,c=0,e;
	for(e=0;e<j+k;e++)
	{
	for(i=0;i<k+j;i++)
	{
		if(ch1[i]==ch1[i+1])
		{	c=c+1;
			ch1[i]=ch1[i-1];
	//	printf("%c %c ",ch1[i],ch1[i+1]);
		}
			
	
	}
	}
	printf("消掉相同字母后:");
	for(i=0;i<j+k+1;i++)
	{
		printf("%c",ch1[i]);
	}
	printf("\n");
}
