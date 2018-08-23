#include<stdio.h>
#include<string.h>
	int i,x;
void change(char x[100]);
void mv (char x[100]);
int main()
{
	char a[100],b[100];
	printf("输入一个字符串:");
	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		if(i=='\n')
		break;
	}	
	change(a);
	printf("重新排序为：");
	printf("%s\n",a);
	printf("再输入一个字符串：");
	for(i=0;;i++)
	{
		scanf("%c",&b[i]);
		if(i=='\n')
		break;
	}	
	change(b);
	printf("重新排序为：");
	printf("%s\n",b);
	strcat(a,b);
	printf("拼接后的结果是：");
	change(a);
	printf("%s\n",a);
	mv(a);
	printf("冊除相同字母结果为");
	printf("%s\n",a);

return 0;
}	

void change (char x[100])
{	
	int t,m,min_a;
	for(t=0;t<100;t++)
		{	
			m=i;
			for(;m>=0;m--)
			{	
				if(x[m]<x[m-1])
				{	
					min_a=x[m];
					x[m]=x[m-1];
					x[m-1]=min_a;
				}
			}
		}
}


void mv (char x[100])
{	
	int j,w;
	for(i=0;i<100;i++)
	{	
		if(x[i]=='\0')
			break;
			if(x[i]==x[i+1])
			{
				w=i;
				for(j=w+1;j<100;j++,w++)
				{
					x[w]=x[j];
				}
			if(x[i]==x[i+1])
				i--;
			}
	}


}























