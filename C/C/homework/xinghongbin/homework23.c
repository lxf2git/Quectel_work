#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void deal_rank(int *p);
int main()
{
		int a[10]={1,2,3,4,5,6,7,8,9,10};
		deal_rank(a);
		return 0;
}
void deal_rank(int *p)
{
		int i,j,k,l;
		int m;
		printf("input num for op\n");
		scanf("%d",&j);
		printf("input num \n");
		scanf("%d",&k);
		j=j-1;
		l=j+k;
		for(;j<10;j++)
		for(i=j;i<l;i++)
		{
				if(*(p+j)<*(p+i))
				{
						m=*(p+j);
						*(p+j)=*(p+i);
						*(p+i)=m;

				}

						
		}
		for(i=0;i<10;i++)
				printf("%d",*(p+i));

}
