#include<stdio.h>
#define R 4
#define C 4
int main()

{   
	int arr[R][C]={};
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(i-j<=0)
			{ arr[i][j]=1;
			  printf("%d",arr[i][j]);
			}
			else{  arr[i][j]=i-j+1;
				printf("%d",arr[i][j]);
		}
                   }
	
	printf("\n");
  	}



	return 0;
}
