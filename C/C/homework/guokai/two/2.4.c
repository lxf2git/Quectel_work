#include<stdio.h>
int main()
{
	int i;
    int n=1;
	float s,d;
	for(i=1;i<9;i++)
	{
			n*=2;
         	s+=(200.0/n);
	        d=100.0/(n*2);
	}
	printf("第10次落地时共经过%f米\n第10次反弹%f高\n",s+100,d);
}		
