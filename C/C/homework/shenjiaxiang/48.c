#include<stdio.h>
#include<stdlib.h>

void print(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",*(p+i));
	}
}
void double_t(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
			*(p+i)=*(p+i)*2;
	}
}

int main()
{
		int n,i;
		int *p;
		void (*pf)(int *,int);
		printf("请选择输入整数个数：\n");
		scanf("%d",&n);
		p = (int *)malloc(n*sizeof(int));
		printf("请输入%d个整数：\n",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",p+i);
		}
		pf=double_t;	
		(*pf)(p,n);
		pf=print;	
		(*pf)(p,n);		
		return 0;
}
