#include<stdio.h>
void zhenghe(int c[4],int a[2],int b[2]);

int main()
{	
	int f,d,i,j;
	int a[2],b[2],c[4];
	printf("inputa:");
	scanf("%d",&f);
	printf("inputb:");
	scanf("%d",&d);
	for(i=0;f!=0;i++)
	{
		j=f%10;
		f=f/10;
		a[i]=j;
	}
	for(i=0;d!=0;i++)
	{
		j=d%10;
		d=d/10;
		b[i]=j;
	}

	zhenghe(c,a,b);
	return 0;
}


void zhenghe(int c[4],int a[2],int b[2])
{	
	int i;
	for(i=0;i<4;i++)
	{
		if(i==0)
		c[i]=b[0];
		else if(i==1)
		c[i]=a[1];
		else if(i==2)
		c[i]=b[1];
		else if(i==3)
		c[i]=a[0];
	}
	for(i=0;i<4;i++)
	{
		printf("%d",c[i]);
	}
	printf("\n");
}






