#include<stdio.h>
int main()
{
	int a=20,b,c;
	b=0;
	c=0;
	for(a=20;a>0;a--)
	{
		b+=1;
		if(b==2)
		{
				b=0;
				a+=1;
		}
		c+=1;
	}
  if(b==1)
	c+=1; 
	printf("可以喝到：%d瓶。\n",c);
	return 0;
}
