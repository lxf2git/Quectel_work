#include<stdio.h>
#include<string.h>


void string1(char a[])
{
	int i;
	printf("输入第一个字符串\n");
	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]==10)
		{
			a[i]='\0';
			break;
		}
	}
	puts(a);
}

void string2(char b[])
{
	int i;
	printf("输入第二个字符串\n");
	for(i=0;;i++)
	{
		scanf("%c",&b[i]);
		if(b[i]==10)
		{
			b[i]='\0';
			break;
		}
	}
	puts(b);
}

void compare(char a[],char b[])
{
	int i,j,n,m,h=0,s=0,x,y,f;
	//puts(a);
	//puts(b);
	n=strlen(a);
	m=strlen(b);
	//printf("2:%d 3:%d",n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//	printf("%c%c",a[i],b[j]);
			if(a[i]==b[j])
			{
				h++;
				y=j;
				x=i;
				while(1)	
				{
					y++;
					x++;
					if(y>=m||x>=n)
					{
						break;
					}
					if(a[x]!=b[y])
					{
						break;
					}
					if(a[x]==b[y])
					{
						h++;
						//printf("1:%d\n",h);
						//continue;
					}
					//h++;	
				}
			//printf("h::%d  ",h);
			if(s<h)
			{
				s=h;
				f=x;
				//printf("3:%d4:%d\n",i,j);
				//y=x;
			}
				h=0;
			//i=x;
			//j=y;
				//y++;
			}
		}
	}
	//printf("%d",s);
	//printf("f-s+1:%d f+1:%d",f-s,f);
	for(i=f-s;i<f;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
}

int main()
{
	char a[100]={0};
	char b[100]={0};
	string1(a);
	string2(b);
	compare(a,b);
	return 0;
}
