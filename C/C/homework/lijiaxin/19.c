#include<stdio.h>
//#include <stdlib.h>为exit的头文件

#define N 10  //宏定义
void inquire(int a[]);
int main()
{
		int i,arr[N];
		printf("please input 10 integer:\n");
		for(i=0;i<N;i++)
		{
				scanf("%d",&arr[i]);
		}
	//	for(i=0;i<N;i++)
	//	printf("%d ",arr[i]);
		inquire(arr);         //调用函数
		return 0;
}
void inquire(int a[])
{
		int p,i;
		printf("please enter pipei integer:\n");
		do
		{
				scanf("%d",&p);
				for(i=0;i<N;i++)
				{
				//		printf("a[%d]=%d",i,a[i]);
						if(p==a[i])
						{
								printf("与数组中第%d位数都为%d\n",i+1,a[i]);
								break;
						}
					/*	if(p!=a[i])
						{		
								printf("you are error,next one:\n");
						}*/
				}
			
		}while(N==i&&printf("Sorry,not find ,next one:\n"));//判断

}











