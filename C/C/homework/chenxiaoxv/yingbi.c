#include<stdio.h>

int main()
{
  	int i,a,b,c,x,y,z,q;
	i==100;
	a==1;
	b==2;
	c==5;
	q=0;
	for(x=0;x<=100;x++)
		for(y=0;y<=50;y++)
			for(z=0;z<=20;z++)	
		{		if(x+y*2+z*5==100)
					q=q+1;
		}
		printf("q=%d\n",q);
	

	return 0;
}
