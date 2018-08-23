#include<stdio.h>
int main()
{
	int i;
	float n=100.0,d,l=0,k=100;
	for(i=0;i<9;i++)
	{   
		
		l=l+k;
	    d=n/2.0;
		
		n=d;
        k=d*2;
	
	
	
	}
	printf("第10次共经过的米数:%f\n",l);
	printf("第10次反弹高度:%f\n",d);

	return 0;
}
