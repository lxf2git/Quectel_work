#include"main.h"

int main()
{
	int i;
	char str1[100]={0},str2[20]={0};
	scanf("%s",str1);
		getchar();
	scanf("%s",str2);
	mystrcpy(str1,str2);
	printf("%s\n",str1);
}


