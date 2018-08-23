#include<stdio.h>
#define N 100

char *count(char *a)
{
	int i;
	printf("输入字符串\n");
	for(i=0;;i++)
	{
		scanf("%c",a+i);
		if(*(a+i)==10)
		{
			*(a+i)='\0';
			break;
		}
	}
	return a;
}

void compare(char *a,char *b)
{
	int i,j,k,x,y,s=0,h=0,f;
	char *p1;
	char *p2;
	char *p3;
	p3=b;
	for(i=0;;i++)
		{
			if(*(a+i)=='\0')
			break;
			for(j=0;;j++)
			{
				if(*(b+j)=='\0')
				//i++;
				break;
				if(*(a+i)==*(b+j))
				{
					x=i;
					y=j;
					h++;
					p1=a+i;
					while(1)
					{
						x++;
						y++;
						if(*(a+x)=='\0'||*(b+y)=='\0')
						{
							break;
						}
						if(*(a+x)!=*(b+y))
						{
							break;
						}
						if(*(a+x)==*(b+y))	
						{
							h++;
								
						}
					}
				}
				if(s<h)
				{
					s=h;
					f=x;
					//printf("%d",h);
					p2=p1;
				}
					h=0;
					b=p3;
			}

		}
		for(i=0;i<s;i++)
		{
			printf("%c",*(p2+i));
		}
		printf("\n");
	/*	j=0;	
		for(i=f-s;i<f;i++)
		{
			*(p1+j)=*(a+i);
			j++;
		}
		//printf("%c",p1);*/
		
}

int main()
{
	char a[N];
	char b[N];
	char *p=a;
	char *q=b;
	//char *p1;
	*p=*count(p);
	*q=*count(q);
	compare(p,q);
	//printf("%s",q);
	return 0;
}
