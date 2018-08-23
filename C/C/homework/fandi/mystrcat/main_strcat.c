#include"main_strcat.h"

int main()
{
	int i;
	char str1[100]={0};
	char str2[20]={0};
	scanf("%s",str1);
		getchar();	
	scanf("%s",str2);
	mystrcat(str1,str2);
	printf("str1:%s\n",str1);
	return 0;
}
