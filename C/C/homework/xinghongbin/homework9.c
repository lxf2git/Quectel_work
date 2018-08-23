#include<stdio.h>
int deal(int a);
main()
{
//		deal(5);
printf("%d\n",deal(20)+20);
return 0;
}

int deal(int a)              //a个空瓶能换多少个空瓶
{
		int m,s;



		static int i;
		i=0;

		s=a/2;               //a个空瓶换出的空瓶
		m=a%2;               //余出的空瓶
		if(s+m!=1)           //总共的空瓶
				deal(s+m);
		i=i+s;
		return i;
}
