#include<stdio.h>
int main()
{
	int z=0,ping=20,kong=0,yu=0;
	do{
		z=ping+z;
		yu=kong%2;
		kong=ping;
		kong=kong+yu;
		ping=kong/2;
	}while(kong>1);
		printf("%d",z);
}
