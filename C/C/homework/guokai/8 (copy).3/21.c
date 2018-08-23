#include<stdio.h>
int main()
{    
     int b,a[100]={0},i=0,j;
	 scanf("%d",&b);
     for(;;)
	 {
		a[i]=b%10;	 
        b=b/10;		
		if(b==0)
		  break;
		else
		    i++;
	 }
	 for(j=i;j>=0;j--)
	 {
	     printf("%d",a[j]+48);
		 printf("\n");
	 }
//	 printf("%d",i);
return 0;
}
