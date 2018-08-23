#include<stdio.h>
int main()
{

	int x,n=0;
	for(x=0;x<=1000;x++)      
{        
	if(x%3==2&&x%5==3&&x%7==1)
	 { 
		n++;
		  if (n%7!=0)
		{ printf("%d ",x);}
		else
		{	printf("\n");
			  
		}
	    }

	     
	 

}	


return 0;
}
