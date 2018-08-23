#include<stdio.h>
#include"str_fun.h"
#define N 20
#define M 10
int main()
{
		char *p1=NULL,*p2=NULL; 
		int value;
		char str1[N]={0};
		char str2[M]={0};
		gets(str1);
		gets(str2);
#if	0
		p1 = mystrcpy(str1,str2);
		printf("%s\n",p1);
#endif
#if 0
		p2 = mystrcat(str1,str2);
		printf("%s\n",p2);
#endif
#if 1
	  	value	= mystrcmp(str1,str2);
		printf("%d\n",value);
#endif


}
