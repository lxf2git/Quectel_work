#include<stdio.h>
#include<stdlib.h>
typedef struct information{
		char *name;
		int *age;
}sIm,**ppsIm,*psIm;
void print(ppsIm q,int n);
int main()
{
		ppsIm p;
		int count,i;
		printf("please input servey people numble:\n");
		scanf("%d",&count);
		getchar();
		p = (ppsIm)malloc(count*sizeof(psIm));
		for(i=0;i<count;i++)
		{
				*(p+i) = (psIm) malloc(sizeof(sIm));
				(*(p+i))->name = (char *)malloc(20);
				(*(p+i))->age = (int *)malloc(20);
				printf("plesae input name age:\n");
				scanf("%s%d",p[i]->name,&((*(p+i))->age));
		}
		print(p,count);
		return 0;
}
void print(ppsIm q,int n)
{
		int i,j;
		i = 0;
		for(j=i;j<n;j++)
		{
				if((q[i]->age)<(q[j]->age))
				{
						i = j;
				}
		}
		printf("name:%s age:%d",q[i]->name,q[i]->age);
}
