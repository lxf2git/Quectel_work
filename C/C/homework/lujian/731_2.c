#include<stdio.h>
#include<time.h>
#define N (10)
 void count_averagre(int a[]);
void deal_score(int a[]);

int main()
{
	int a[N], i; 
	srand(time(NULL));

	for (i = 0; i < N; i++)
	{
		a[i] = rand()%100;
		printf("the %d boss give scores:%d \n",i, (rand()%100));
	}
	
	deal_score(a);	
	count_averagre(a);


	return 0;
}

void deal_score(int a[])
{
	int i, k, l,temp;
	
	for (i = 0,k = i; i < N ; i++)
	{
		if (a[k] > a[i])
				a[k] = a[i];
	}
	temp = a[k];
	a[k] = a[N-1];
	a[N-1] = temp; 
	for (i = 0, l = i; i < N; i++)
	{
		if (a[l] > a[i])
				a[l] = a[i];

	}
	temp = a[l];
	a[l] = a[N-2];
	a[N-2]= temp;
}
 void count_averagre(int a[])
{
	float sum;
	int i;
	
	for (i = 0; i < N-2; i++ )
	{
		sum+=a[i];
	}
 	
	printf(" the average_score:%5.2f\n",(sum/10.0));

}


