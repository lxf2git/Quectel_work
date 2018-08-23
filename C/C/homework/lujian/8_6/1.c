#include<stdio.h> 

int deal_a(int a[], int n);
int input(int a[]);
#define  N (100)

int main() 
{

	int a[100]={};

	input(a);
	
	deal_a(a, 0);// qiu ou

	deal_a(a, 1);// qiu ji

	return 0; 
}


int input(int a[])
{
	
	int i;
	printf("please input number:\n");
	for (i =0; i<N; i++)
	{
		scanf("%d",&a[i]);

		if ( a[i] == 0  )
			break;	

	}		

	 return 0; 
}

int deal_a(int a[], int n)
{
	int i, count = 0, sum = 0;
	float aver;


	for (i = 0; i<N; i++)

	{
			if ((a[i]+n)%2==0 && a[i] != 0) 
			{

					sum += a[i];
					count++;
			}			
		

	}

	if (count == 0)
	{
			aver = 0;
			if (n==0)
			{
					printf("even_number 's number:%d\neven_number's average:%5.2f\n",
									count, aver); 
			}
			else
					printf("uneven_number 's number:%d\nuneven_number's average:%5.2f\n",
									count, aver); 
			 

	}
	else if(count>0)
	{


			aver = sum/count;


			if (n==0)
			{
					printf("even_number 's number:%d\neven_number's average:%5.2f\n",
									count, aver); 
			}
			else
					printf("uneven_number 's number:%d\nuneven_number's average:%5.2f\n",
									count, aver); 
	}
	return 0;

	

	 



}
























