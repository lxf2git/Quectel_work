#include<stdio.h>
char *mystrcpy(char *dest,char *src)
{	
		int i;
		for(i=0;i<20;i++)
		{
		    *(dest+i)=*(src+i);
		}
	return dest;
}
int main()
{
	char str1[20]="hello";
	char str2[20]="world";
	char *p =mystrcpy(str1,str2);
	printf("%s\n",p);	
return 0;
}
