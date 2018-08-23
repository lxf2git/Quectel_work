#include<stdio.h>
int main()
{
	char ch;
	int cha=0,line=0;
	printf("输入字符串");
	for(;;)
	{

		scanf("%c",&ch);
		cha++;
		if(ch=='.')
		{
			line++;
			printf("%d\n",cha-1);
			printf("%d\n",line);
			printf("\n");
			cha=0;

		}
		if(ch=='\n')
		{
			return 0;

		}

	}





}

