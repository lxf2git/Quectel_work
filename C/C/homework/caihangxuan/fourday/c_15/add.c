#include"add.h"
int nu=0;
int i;
int c=0;
int add(int nu, int geshu)
{   printf("%d",geshu);
  do{
        nu=nu+i;
	i=nu;
	c++;
    }while(c!=geshu);
	printf("和为%d",nu);
}
