#include"cp.h"
int cp(int a[])

{
	int m,n,i,x,y;
	m=a[0];
	
	n=a[4];
	
	for(i=0;i<5;i++)
	{
		if(m<a[i])
			m=a[i];
		if(n>a[i])
			n=a[i];
	}
			a[4]=m;
			a[0]=n;
}
