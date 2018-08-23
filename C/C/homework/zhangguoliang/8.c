#include<stdio.h>
int main()
{
	int i;
	float h=100,y=0,z=0;
	for(i=1;i<11;i++)
	{
		y=h+h/2;
		h=h/2;
		z=y+z;
	}
	printf("反弹：%f\n",h);
	printf("共经过：%f\n",z);
	return 0;
}
