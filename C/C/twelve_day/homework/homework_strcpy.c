#include<stdio.h>

char *my_strcpy(char *dest,char *src)
{
	char *ptmp = dest;	
	while(*src!='\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
/*
 	char *save = dst;
	while((*dst++=*src++)!='\0')
	;
	return save;
 * */
	return ptmp;
}
int main()
{
	char src[20]="i am fine";
	char des[50]="how are you";
	printf("%s",my_strcpy(des,src));	
	return 0;

}
