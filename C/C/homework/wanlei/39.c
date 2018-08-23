#include<stdio.h>

#define N 100
#define N 100
void search(char *p1, char *p2);

int main()
{
	char a[N];
	char b[N];
	char *p1,*p2;
	p1=a;
	p2=b;
	printf("请输入字符串一\n");
	scanf("%s",p1);
	printf("请输入字符串二\n");
	scanf("%s",p2);
	//int m=strlen(a);
	//int n=strlen(b);
	search(p1,p2);
	//puts(a);
	//puts(b);
	return 0;
}

void search(char *p1, char *p2)
{
	char *p3;
	char *p4;
	char *p2_start;
	p2_start=p2;
	//printf("%p %p\n",p2,p2_start);
	int max=0;
	int i,n=0;
	while(*p1!='\0')
	{
		while(*p2!='\0')
		{
			if(*p1==*p2)
			{
				n=0;
				n++;
				p3=p2;
				//printf("*p3:%c ",*p3);
				while(*p1!='\0'&&*p2!='\0')
				{
					p1++;
					p2++;
					if(*p1==*p2)
					{
						n++;
						//printf("%d ",n);
					}
					else
					{
						break;
					}
				}	
			}
			//printf("*p2:%c ",*p2);
			p2++;
			if(max<n)
			{
				max=n;
				p4=p3;
			}
		}
		//printf("*p1:%c ",*p1);	
		p1++;
		p2=p2_start;
	}
	//printf("\n");
	printf("*p4:%c max:%d",*p4,max);
	printf("\n");
	printf("最大公共子串为：");
	for(i=0;i<max;i++)
	{
		printf("%c",*(p4+i));
	}
	printf("\n");
}
