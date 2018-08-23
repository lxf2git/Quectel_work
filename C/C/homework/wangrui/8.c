#include<stdio.h>

int main()
{
	float h,l;
	int i,b;

	l=100;
	h=100;
	printf("第几次落地?\n ");
	scanf("%d",&b);
	

	for(i=0;i<b;i++)
	{
		if(i>=1)l=l+2*h;
		h=h/2;
	}

	printf("落地时经过%f米\n第十次反弹高%f米\n",l,h);

	return 0;
}
