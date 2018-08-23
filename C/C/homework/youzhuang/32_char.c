#include<stdio.h>
#include<string.h>

#define N 100

void input(char a[]);
void print(char a[]);
void extract(char a[],char b[],char c[]);
int main()
{
		char a[N],b[N],c[N];
		printf("请输入字符串a:\n");
		input(a);
		printf("请输入字符串b:\n");
		input(b);
		extract(a,b,c);
		printf("最大公共子串:\n");
		print(c);
		return 0;
}

void input(char a[])
{
		gets(a);
}

void print(char a[])
{
		puts(a);
}

void extract(char a[],char b[],char c[])
{
		int i,j,k,count,max=0;
		int start=-1,end,mstart=-1,mend=-1;
		for(i=0;i<strlen(a);i++)
		{
				for(j=0;j<strlen(b);j++)
				{
						count=0;
						if(a[i]==b[j])
						{
								start=i;
								end=i;
								count++;
								k=1;
								while(1)
								{
										if(a[i+k]==b[j+k]
										&&(i+k)<strlen(a)
										&&(j+k)<strlen(b))
										{
												count++;
												end=i+k;
										}
										else
										{
												break;
										}
										k++;
								}
						}
						if(max<count)
						{
								max=count;
								mstart=start;
								mend=end;
						}
				}
		}
		j=0;
		for(i=mstart;i<=mend;i++)
		{
				c[j]=a[i];
				j++;
		}
		c[j]='\0';
}

