#include<stdio.h>
char * mystrcpy(char *dest,char *src)
{
	....;
	return dest;
}

int main()
{		
#if 1	
	char str[20]="hello";
	char str2[]="wo";
	char *p = mystrcpy(str,str2);
	printf("%s\n",p);	
#endif
	return 0;

}
