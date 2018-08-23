#include<stdio.h>

#define N 41

int sum(int a[]);
void kill(int a[]);
void check(int a[]);

int main()
{
	int a[N]={0};
	kill(a);
   	//for(i=0;i<10;i++)
	//printf("%d",a[i]);
	check(a);
	return 0;   
}

/*int sum(int a[])
{
	int s=0;
	int i;
	for(i=0;i<10;i++)
	{
		s=s+a[i];
	}
	return s;
}*/

void check(int a[])
{
	//printf("**");
	int i;
	for(i=0;i<N;i++)
	{
		if(a[i]==0)
		{
			printf("最后活着的幸运者%d\n",i+1);
		}
	}
}

void kill(int a[])
{
	int i,j=0;
	int n=N;	
   	for(i=0;i<N;i++)
   	{
		if(a[i]==0)
		{
			printf("杀");
			j++;
   			if(j%3==0)
			{
				printf("就是你:%d\n",i+1);
				a[i]=1;
				n--;
			}
		}
		if(n==1)
			break;
		if(i==N-1)
		{
			i=-1;
		}
   	}
}
