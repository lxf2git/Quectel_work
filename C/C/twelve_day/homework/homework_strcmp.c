#include<stdio.h>

int my_strcmp(char *dest,char *src)
{
	int temp;	
	while(*dest==*src)
	{
		if(*dest=='\0')
		{
			return 0;
		}
		src++;
		dest++;
	}
	temp = *dest-*src;
	if(temp==0)
	{
		return 0;
	}
	else if(temp<0)
	{
		return -1;
	}
	else if(temp>0)
	{
		return 1;
	}
}
int main()
{
	char src[20];
	char des[50];
	gets(src);
	gets(des);
	printf("%d",my_strcmp(des,src));	
	return 0;

}
