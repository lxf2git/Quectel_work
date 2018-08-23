#include<stdio.h>
int main()
{
	int i,j,k,n=0;  //fen1,fen2,fen3
	for(i=0;i<101;i++)
	{		
	
	   for(j=0;j<51;j++)
	   { 
			   for(k=0;k<21;k++)
			   {
				  if(i*1+j*2+k*5==100)
				  {	  
		          printf("兑换方法:%d%d%d\n",i,j,k);
           		  n++;
				  }
			   }  
	   }  
	}   
     	   
		printf("方法总数:%d\n",n);			
	return 0;
}
