#include<stdio.h>
#define N 100

char mystrcat(char *dest,char *scr)
{
	char a[N];
	for(;;)
	{
		if(*dest=='\0')
		{
			for(;;)
			{
				if(*scr=='\0')
						return a;
				*dest=*scr;
				dest++;
				scr++;	
			}
		}
		dest++;
	}

}

int main()
{
	char str1[N],str2[N];
	printf("请输入字符串a：\n");
	gets(str1);
	printf("请输入字符串b：\n");
	gets(str2);
	mystrcat(str1,str2);
	printf("%s\n",str1);

	return 0;
}
