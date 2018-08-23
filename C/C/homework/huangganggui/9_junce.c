#include<stdio.h>

int main()
{
	int full=20,empty=0;
	int c=0,i=0;        

	while(full!=0)
	{
		
		c=c+full;							//count full botton
		empty=full+i;						//空瓶数
		i=empty%2;	
		full=empty/2;    					//空瓶子换 满瓶
	}
	printf("The number of juice you can drink is %d\n",c);
	return 0;
}
