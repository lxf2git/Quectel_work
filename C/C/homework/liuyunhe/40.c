#include<stdio.h>
#include<stdlib.h>
int main()
{
		int **p=NULL;
		int n,m;
		int i,j;
		int min2;
		printf("输入二维数组的行 列\n");
		scanf("%d%d",&n,&m);
		p=(int **)malloc(n*sizeof(int *));
		//printf("%p",p);
		printf("输入%d个数\n",n*m);
		for(i=0;i<n;i++)
		{
				*(p+i) = (int *)malloc(m*sizeof(int));
		}
		
		for(i=0;i<n;i++)
		{
				for(j=0;j<m;j++)
				{
						scanf("%d",*(p+i)+j);
				}
		}

		int min=**p;

		for(i=0;i<n;i++)    //找最小值
		{
				for(j=0;j<m;j++)
				{
						if((*(*(p+i)+j))<min)
						{
								min=*(*(p+i)+j);
						}
				}
		}

		if(**p>min)
		{
			 min2 = **p;
		}
		else
		{
			min2 = *(*(p)+1);
		}
		for(i=0;i<n;i++)    //找第二小值
		{
				for(j=0;j<m;j++)
				{

						if((*(*(p+i)+j))<min2)
						{

								if((*(*(p+i)+j))>min)
								{
							 			min2=*(*(p+i)+j);
								}
						}
						
				}
		}
		
		printf("第二小值:%d\n",min2);
		return 0;
}
