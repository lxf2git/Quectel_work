#include"./sort.h"
//#include<stdio.h>
//int main()
//{	
//void sort(int arry[],int n);
void sort(int arry[],int n)
{		
	int i,j,k=0,t;
 	for(i=0;i<n-1;i++)
	{
	//	k=i;
		for(j=i+1;j<n;j++)
			{
				if(arry[j]<arry[i])
				{t=arry[j];
				arry[j]=arry[i];
				arry[i]=t;}
			}
//	for(i=0;i<=10;i++)
	// printf("%3d",arry[i]);  	
	}
}	
 //   return 0;
//}	
