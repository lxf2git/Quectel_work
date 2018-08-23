#include<stdio.h>
int max();
int min();

int main()
{
 int a,b,c,m,n;
 
 scanf("%d%d%d",&a,&b,&c);
m=max(a,b,c);
n=min(a,b,c);
printf("%d\n",m);
printf("%d\n",n);
printf("%d\n",m-n);
}


int max(int a,int b,int c)

{
		int z,m;
		z=a>b?a:b;
		m=z>c?z:c;
		return(m);


}
int min(int a,int b,int c)
{
	int n,m;

	if(a<b)
	n=a;
	else
	n=b;
	if(n<c)
	m=n;
	else
	m=c;
return m;





}
