#include<stdio.h>
int main()
{
	float height=0,i,tall=100;
	for(i=9;i>0;i--)
	{	
		height=tall+height;
		tall=tall/2;
	}
	height=height+100;
	printf("共%f米\n,第十次%f米。\n",height,tall);
}
