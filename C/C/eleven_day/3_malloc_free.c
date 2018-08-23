#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p=NULL;
	int n,i;
	printf("please input the number of inter:\n");

	scanf("%d",&n);//int arr[n];
	
	 p = (int *)malloc(n*sizeof(int));	//

	 for(i=0;i<n;i++)
	 {
	 	scanf("%d",p+i);//&p[i] &(*(p+i))
	 }
	 
	 for(i=0;i<n;i++)
	 {
	 	printf("%d\n",p[i]);//&p[i] &(*(p+i))
	 }

	if(p!=NULL)
	{
		free(p);
		p = NULL;
	}

	//p[2]=90;
	//printf("p[2]:%d\n",p[2]);
	return 0;

}




