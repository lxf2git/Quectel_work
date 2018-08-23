#include<stdio.h>
int change(int a,int b);
 
int main()
{
	int a,b,c;
	printf("Input 2 integer(10~99):");
	scanf("%d%d",&a,&b);
	if( (a > 9 && a < 100)&&(b > 9 && b < 100) )
		c = change(a,b);
	else
	{
		printf("err !\n");
		return 0;
	}
	printf("c:%d\n",c);
	return 0;
}

int change(int a,int b)
{
	int c=0,unit=0,decade=0;
	
	unit=a%10;
	decade=a/10;
	c= c+unit*1+decade*100;
	
	unit=b%10;
	decade=b/10;
	c= c+unit*1000+decade*10;

	return c;

}
