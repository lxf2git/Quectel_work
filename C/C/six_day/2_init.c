#include<stdio.h>

int main()
{
	int i;	
	char string[5]={'h','e','l','l','o'};	
	char string2[5]={'h','e','l'};
	char string3[5]={'\0'};
	char string4[5]={'h','e','l','l','\0'};	
	char string5[5]={"hell"};
	char string6[500];
#if 0
	for(i=0;i<5;i++)
	{
		string6[i] = getchar();//scanf("%c",&string6[i]);
		putchar(string6[i]);
	}
#endif
#if 0	
	printf("input a string:\n");
	gets(string6);//scanf("%s",string6);
	puts(string6);//printf("string6:%s\n",string6);
#endif
	gets(string6);//scanf("%s",string6);
	//printf(string6);
	puts("i am fine");
	return 0;
			
}
