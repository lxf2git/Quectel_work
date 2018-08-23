#include<stdio.h>
#define R 2
#define C 3

int main()
{
	int i,j;
	int a[2][3]={10,20,30,40,50,60};	

	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("&a[%d][%d]:%p  ",i,j,&a[i][j]);
		}
		printf("\n");
	}
	
	printf("a:%p   *a:%p   a[0]:%p   &a[0][0]:%p\n",
					a,*a,a[0],&a[0][0]);

	printf("*a+1:%p  a[0]+1:%p  \n",*a+1,a[0]+1);
	printf("*(*a+1):%d  *(a[0]+1):%d  \n",*(*a+1),*(a[0]+1));
	//a[0][1]    *(*(a+0)+1)   
	//a[1][2]   a+1
	return 0;


}

