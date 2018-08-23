#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[3];	
	int *p=NULL;
	int n,i;
	printf("please input the number of inter:\n");

	scanf("%d",&n);//int arr[n];
	
	/*void * 原始指针 类型未知的指针
	  void a;//空间
  	  void *p;	//4  
	*/
	 p = (int *)malloc(n*sizeof(int));	//
	
	 for(i=0;i<n;i++)
	 {
	 	scanf("%d",p+i);//&p[i] &(*(p+i))
	 }
	 
	 for(i=0;i<n;i++)
	 {
	 	printf("%d\n",p[i]);//&p[i] &(*(p+i))
	 }

	// printf("sizeof(p):%d sizeof(arr):%d\n",sizeof(p),sizeof(arr));
	return 0;

}




