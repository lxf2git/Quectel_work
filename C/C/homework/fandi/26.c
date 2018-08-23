#include<stdio.h>
#define N 5
int combare_min(int arr[][N])
{
	int n=0,i,j,t=arr[0][0],m;
	for(i=0;i<N;i++)
			for(j=0;j<N;j++){
					if(t>arr[i][j-n]){
						m=arr[i][j-n];
						arr[i][j-n]=t;
						t=m;
					}
			}
	return t;
}

int combare_max(int arr[][N])
{
	int i,j,t=arr[1][0],m;
	for(i=1;i<N;i++)
			for(j=0;j<=i-1;j++){
					if(t<arr[i][j]){
							m=arr[i][j];
							arr[i][j]=t;
							t=m;
					}
			}
	return t;
}


int main()
{
	int a[N][N],i,j,max,min;
	for(i=0;i<N;i++)
			for(j=0;j<N;j++)
					scanf("%d",&a[i][j]);
	max=combare_max(a);
	min=combare_min(a);
	printf("左下角最大数:%d\n",max);
	printf("右上角最小数:%d\n",min);	
	return 0; 
}
