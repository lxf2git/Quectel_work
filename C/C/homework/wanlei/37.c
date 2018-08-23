#include<stdio.h>
#include<stdlib.h>
#define N 100
#define M 50

char *my_strcpy(char *dest,char *src);
char *my_strcat(char *dest,char *src);
int my_strcmp(char *s1,char *s2);
int my_strlen(char *s);

int main()
{
	 char a[N];
	 char b[M];
	 int i,j;
	 char *p1,*p2;
	 p1=a;
	 p2=b;
	 printf("请输入字符串a\n");
	 scanf("%s",p1);
	 printf("请输入字符串b\n");
	 scanf("%s",p2);
	 //puts(a);
	 //puts(b);
	 char *point_1,*point_2;
	 int m,n,o;
	 int x;
	 printf("请选择使用的函数\n");
	 printf("1:strcpy\n");
	 printf("2:strcat\n");
	 printf("3:strcmp\n");
	 printf("4:strlen\n");
	 printf("其他：退出\n");
	 scanf("%d",&x);
	 switch(x)
	 {
			 case 1:
 	 			point_1=my_strcpy(p1,p2);
				puts(point_1);
				break;
			 case 2:
	 			point_2=my_strcat(p1,p2);
				puts(point_2);
				break;
			 case 3:
	 			m=my_strcmp(p1,p2);
				printf("%d\n",m);
				break;
			 case 4:
				n=my_strlen(p1);
				o=my_strlen(p2);
				printf("a:%d\n",n);
				printf("b:%d\n",o);
				break;
			 default:
				exit(0);
	 }
	 return 0;	 
}
#if 1
char *my_strcpy(char *dest,char *src)
{
	int i;
	for(i=0;;i++)
	{
		*(dest+i)=*(src+i);
		if(*(src+i)=='\0')
		{
			*(dest+i)='\0';
			break;
		}
	}
	return dest;
}
char *my_strcat(char *dest,char *src)
{
	int i;
	for(i=0;;i++)
	{
		if(*(dest+i)=='\0')
		{
			*(dest+i)=*src;
			src++;
			*(dest+i+1)='\0';
			if(*src=='\0')
			{
				break;
			}
		}
	}
	return dest;
}

int my_strcmp(char *s1,char *s2)
{
	int i;
	int a;
	for(i=0;;i++,s1++,s2++)
	{
		a=*s1-*s2;
		if(a!=0)
		{
			break;
		}
		if(*s1==0||*s2==0)
		{
			break;
		}
	}
	return a;
}

int my_strlen(char *s)
{
	int i=0;
	while(*s!='\0')
	{
		s++;
		i++;
	}
	return i;
}
#endif
