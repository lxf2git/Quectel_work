#include<stdio.h>

int max_1(int num_a,int num_b,int num_c);
int min_1(int num_a,int num_b,int num_c);

int main()
{
	int num_a,num_b,num_c;
	int max,min;
	
	scanf("%d%d%d",&num_a,&num_b,&num_c);	
		
	max = max_1(num_a,num_b,num_c);
	min = min_1(num_a,num_b,num_c);

	printf("max:%d min:%d sub:%d\n",max,min,max-min);
		
	return 0;		
}


int max_1(int num_a,int num_b,int num_c)
{
	int i,j;
	
	i = num_a>num_b?num_a:num_b;
	j = i>num_c?i:num_c;
	
	return(j);	
				
}


int min_1(int num_a,int num_b,int num_c)
{
	int i,j;	
	
	i = num_a<num_b?num_a:num_b;
	j = i<num_c?i:num_c;
		
	return(j);
}















