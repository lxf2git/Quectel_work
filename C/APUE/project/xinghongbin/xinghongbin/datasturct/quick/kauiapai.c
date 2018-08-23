#include<stdio.h>
#include<time.h>
#include"stack.h"
int deal(int l,int h,int *a);
void swap(int *p,int*q);
//void quick_sort(int l,int h,int *a);
void quick_sort(int l,int h,int *a,pSta pStack);
int main()
{
		pSta pStack;
		stack_init(&pStack);
		srand(time(NULL));
		int i;
		int a[100];
		for(i=0;i<100;i++)
		{
				a[i] = rand()%100;
		}
		quick_sort(0,99,a,pStack);
//		quick_sort(0,99,a);
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
				while((flag <a[h])&& (h!=l))
				{
						h--;
				}	

				if((flag>=a[h])&&(h!=l))
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

void quick_sort(int l,int h,int *a,pSta pStack)
{
		int ret = 1;
		while(ret !=0)
		{
				printf("prev\n");
				push(pStack,l);
				ret = deal(l,h,a);
//				push(pStack,ret);
				while(ret+1 <h)
				{
						printf("mid\n");
						push(pStack,ret+1);
						ret = deal(ret+1,h,a);
//						push(pStack,ret);

				}
				do
				{
						if(pStack->bottom->next == pStack->bottom)
								return;

//						pop(pStack,&ret);
						pop(pStack,&l);
						printf("last\n");
				}while(ret-1 <=l);
				h = ret-1;

				
		}//ret  he   l bushi   yiqi de   l shi shangci de ;

}

/*
void quick_sort(int l,int h,int *a)
{
		int ret;
		ret = deal(l,h,a);
		
		if(ret+1 <h)
		quick_sort(ret+1,h,a);
		if(ret-1 >l)	
		quick_sort(l,ret-1,a);
}
*/
void swap(int *p,int*q)
{
		int temp;
		temp = *p;
		*p = *q;
		*q = temp;
		
}
