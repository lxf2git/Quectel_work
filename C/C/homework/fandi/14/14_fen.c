#include"14_fen.h"


char fen(char x)
{
	int z;
	z=0;
	for(;;)
	{
	scanf("%c",&x);
	if(x!='\n')
	{
	if(x>=48&&x<=57)
		z+=1;
	}
	else
		break;
	}

	printf("该数字共有:%d位\n",z);
	return z;
}
