#include<stdio.h>

int main()
{
//while(1)
//{
	int ch;
	int character=0,space=0,other=0,number=0;
	while((ch=getchar())!=10)
	{
		if(((ch>=97)&&(ch<=123))||((ch>=65)&&(ch<=91)))
			character++;
		else if(ch>='1'&&ch<='9')
			number++;
		else if(ch==' ')
			space++;
		else
			other++;
	}
		printf("character:%d\n",character);
		printf("number:%d\n",number);
		printf("space:%d\n",space);
		printf("other:%d\n\n",other);
			
//}	

	return 0;
}
