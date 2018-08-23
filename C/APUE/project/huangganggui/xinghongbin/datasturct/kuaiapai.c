#include<stdio.h>
#include<time.h>
int deal(int l,int h,int *a);
void swap(int *p,int*q);
void quick_sort(int l,int h,int *a);
int main()
{
		int i;
		srand(time(NULL));
		int a[100];
		for(i=0;i<100;i++)
		{
//				printf("input:");
//				scanf("%d",a+i);
								
				a[i] = rand()%100;
		}
		quick_sort(0,99,a);
		for(i=0;i<100;i++)
		{
				printf("%d\n",a[i]);
		}

}
int deal(int l,int h,int *a)
{
		int i=l;
		int flag = a[i];
		while(h != l)
		{
				while((flag < a[h])&& (h!=l))
				{
						h--;
				}	

				if((flag>=a[h]) &&(h !=l))
				{
						swap(&a[i],&a[h]);
						i = h;
						l++;
						
				}
				while((flag >= a[l])&& (h!= l))
				{
						l++;
				}	
				if((flag<a[l]) &&(h!=l))
				{
						swap(&a[i],&a[l]);
						i =l;
						h--;
				}
				
		}
		return i;
}
void quick_sort(int l,int h,int *a)
{
		int ret;
		ret = deal(l,h,a);
		
		if(ret+1 <h)
		quick_sort(ret+1,h,a);
//		if(ret == h)
//				return;
		if(ret-1 >l)	
		quick_sort(l,ret-1,a);
//		if(ret == l)
//				return;

}
void swap(int *p,int*q)
{
		int temp;
		temp = *p;
		*p = *q;
		*q = temp;
		
}
