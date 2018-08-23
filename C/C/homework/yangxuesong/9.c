#include<stdio.h>
int main()
{
	int i=20,x=20,y=0;
while(x>1)
{
	i=i+(x+y)/2;
	x=x/2;
	y=x%2;
	
}	
	printf("%d",i);
	return 0;
}
