#include<stdio.h>
int main()
 {	
	int x=0,y=0,m,z;
	for(m=0;m<9;++m)
{
	 y++;
	 x=0;  
	for(;;)
{	
	x++;
	    if(x==y)	
	{
	   printf("%d*%d=%d ",x,y,z=x*y);
	   printf("\n");
	    break;
        }
	else
	   printf("%d*%d=%d ",x,y,z);
}
}
return 0;
}
