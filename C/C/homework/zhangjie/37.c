#include<stdio.h>
#include<stdlib.h>
#define N 50
#define M 100
int m,n;



char *my_strcpy(char *dest,char *src);
char *my_strcat(char *dest,char *src);
char *my_strcmp(char *dest,char *src);

int main()
{
	char a[M];
	char b[N];
	char *p=a;
	char *p1=b;
	int i,j,s;
	for(i=0;i<N;i++)
	{
		scanf("%c",p+i);
		m++;
		if(*(p+i)==10)
		{
			*(p+i)='\0';
			m--;
			break;
		}
	}
	for(j=0;j<N;j++)
	{
		scanf("%c",p1+j);
		n++;
		if(*(p1+j)==10)
		{
			*(p1+j)='\0';
			n--;
			break;
		}
	}
	scanf("%d",&s);
	switch(s)
	{
		case 1:
		*p=*my_strcpy(p,p1);
		break;
		case 2:
		*p=*my_strcat(p,p1);
		break;
		case 3:
		*p=*my_strcmp(p,p1);
		{
			printf("%d",*p);
			exit (0);
		}		
	}
	printf("%s\n",p);

	//printf("%d",f);
	//printf("%s",p);
	//printf("%s",p1);
	return 0;
}



char *my_strcpy(char *dest,char *src)
{
	int i;
	for(i=0;;i++)
	{
		*(dest+i)=*(src+i);
		if(*(src+i)=='\0')
		break;
	}
	return dest;
}


char *my_strcat(char *dest,char *src)
{
	int i,j=0;
	for(i=m;;i++)
	{
		*(dest+i)=*(src+j);
		j++;
		if(*(dest+j)=='\0')
		break;
	}
	return dest;
}



char *my_strcmp(char *dest,char *src)
{
	int i,c;
	int *d;
	char *e;
	d=&c;
	for(i=0;;i++)
	{
		if(*(dest+i)==*(src+i))
		{
			continue;
		}
		if(*(dest+i)<*(src+i))
		{
			c=*(dest+i)-*(src+i);
			break;
		}
		if(*(dest+i)>*(src+i))
		{
			c=*(dest+i)-*(src+i);
			break;
		}		
	}
	e=(char *)d;
	return e;	
}
