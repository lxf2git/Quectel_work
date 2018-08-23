#include<stdio.h>

int main()
{
float t,a,h,l;
h=100;
l=0;
t=0;
for(a=1;a<11;a++)
	{t=h/2;
	 h=t;	
	 l=l+h*2;
	}
	l=l+100;
	printf("共:%f\n",l);
	printf("剩:%f\n",h);

return 0;

}
