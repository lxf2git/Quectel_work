#include<stdio.h>

int main()
{
	int i;	
	char string[5]={'h','e','l','l','o'};	
	char string2[5]={'h','e','l'};
	char string3[5]={'\0'};
	char string4[5]={'h','e','l','l','\0'};	
	char string5[5]={"hell"};
	char string6[5];
#if 0
	for(i=0;i<5;i++)
	{
		scanf("%c",&string6[i]);
		//getchar();
		printf("%c ",string6[i]);
	}
#endif
	printf("input a string:\n");
	scanf("%s",string6);
	printf("string6:%s\n",string6);

	return 0;
			
}
