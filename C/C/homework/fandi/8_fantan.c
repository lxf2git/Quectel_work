#include<stdio.h>
int main()
{
	int i;
	float h,x;
	h=100.0;
	x=100.0;
	for(i=1;i<=10;i++)
	{
		h=h/2;
		x=x+2*h;
		if(i==10)
		{
			printf("第十次反弹高度为:%f\n",h);
		}
	}
	printf("弹起十次小球所走的路程为:%f\n",x);
	return 0;
}
