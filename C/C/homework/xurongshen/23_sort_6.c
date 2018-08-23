#include<stdio.h>
#include<string.h>
#define N 10

void exchange(int arr[N],int m,int n);
void output(int arr[N]);

int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int brr[N]={0};
	int i,n;
	printf("请输入逆序的位置 个数\n");
	scanf("%d%d",&i,&n);

	printf("逆序的位置是%d，个数：%d\n",i,n);

	exchange(arr,i,n);
	output(arr);
	return 0;
}
void exchange(int *p,int m,int n)
{
	int i=0,j,t,k;
	j=m+n-2;
//	k = (m+j)/2;
	for(i=0;i<N;i++)
	{
		if(m == (i+1))
		{
			do{
				t = p[j];
				p[j] = p[i];
				p[i] = t;
				i++;
				j--;
//				printf("exchange---->i:%d,j:%d\n",i,j);
			}while(i<j);
			break;
//			printf("exchange---->if do--->\n");
		}
	}
//	printf("exchange--->out--->bb\n");
}

void output(int *p)
{
//	printf("output--->aa!\n");
	int i;
	for(i=0;i<N;i++)
	{
		printf("%3d",p[i]);
	}
	printf("\n");
}
