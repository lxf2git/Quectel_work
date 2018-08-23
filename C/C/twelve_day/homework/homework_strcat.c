#include<stdio.h>
#include<string.h>

char *my_strcat(char *dst,char *src)
{
		strcpy(dst+strlen(dst),src);
		return dst;
}
int main()
{
	char src[20]="i am fine";
	char des[50]="how are you";
	printf("%s",my_strcat(des,src));	
	return 0;

}
