#include<stdio.h>
#include<string.h>
#define N 20
void mycpy(char *p,char *p1);
void mycat(char *p,char *p1);
int mycmp(char *p,char *p1);
int main() 
{
		char dest[N]={};
		char src[N]={};
		printf("dest: ");
		gets(dest);
		printf("src: ");
		gets(src);
		mycpy(dest,src);
		printf("cpy: ");
		//mycat(dest,src);
		//printf("cat: ");
		//int com = mycmp(dest,src);
		//printf("%d",com);
		puts(dest);
}
void mycpy(char *p,char *p1)
{
		for(;;p++,p1++)
		{
			*p=*p1;
			if(*p=='\0')
			{
					break;
			}
		}
}
void mycat(char *p,char *p1)
{
		int len=strlen(p);
		for(;*(p+len-1)!='\0';p++,p1++)
		{	
			*(p+len)=*p1;
		}
}
int mycmp(char *p,char *p1)
{
		for(;;p++,p1++)
		{
			if(*p>*p1)
			{
					return 1;
			}
			if(*p<*p1)
			{
					return -1;
			}
			if(*p=='\0')
			{
					return 0;
			}
		}
}
