#include<stdio.h>
void show(int N);
int main()
{
	int n;
    printf("please input in :\n");
    scanf("%d",&n);
	show(n);
	return 0;
}
void show(int N)
{		
    int n=0,i,j,m,l;	
    int a[N][N];
	for(i=0;i<N;i++)
	{  
		n++;
		m=n;
		for(j=0;j<N;j++,m--)
		{
		  if(i>j)
		  {
		   a[i][j]=m;
	      }	   
		  else
          {		
			a[i][j]=1; 
		  }
	    	printf("%d ",a[i][j]);
		}
	   printf("\n");
	}
}	
