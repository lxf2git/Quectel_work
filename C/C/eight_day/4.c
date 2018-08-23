#include<stdio.h>
#define N 6
#define TOS(a)   ((a)>=65&&(a)<=90)?(a)+32:(a)
int main()
{

	char c;
	scanf("%c",&c);
	printf("%c\n",TOS(c));
	return 0;

}
