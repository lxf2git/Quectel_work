#include<stdio.h>
#define N 100

char mystrcpy(char *dest,char *scr)
{
		int i;
	for(i=0;i<N;i++)
	{	
		*dest=*scr;
	//	printf("%d  ",i);
		//printf("%c   ",*dest);
	//	printf("%c   ",*scr);
		if(*scr=='\0')
		{
			return 0;
		}
		scr++;
		dest++;
	//	printf("%c   ",*dest);
	}
}


int main()
{
	char str1[N],str2[N];
	printf("请输入字符串a：\n");
	gets(str1);
	printf("请输入字符串b：\n");
	gets(str2);
	mystrcpy(str1,str2);
	puts(str1);
	return 0;
}
