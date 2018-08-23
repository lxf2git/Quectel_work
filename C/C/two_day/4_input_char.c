#include<stdio.h>

int main()
{
	char ch;
	do
	{
		scanf("%c",&ch);
		getchar();
		printf("%c\n",ch);
	}while((ch<'A'||ch>'z'||(ch>'Z'&&ch<'a'))&&printf("input a char:\n"));

	return 0;
}
