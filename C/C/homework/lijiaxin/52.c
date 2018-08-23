#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct Elector{
		char name[20];
		int count;
}sEle,*ppse,*psEle[3];
void compare(psEle q);
int main()
{
		int i,num;
		int ch;
	   	psEle p;
		for(i=0; i<=2; i++)
		{
				*(p+i) = (ppse)malloc(sizeof(sEle));

				printf("please enter choosed people:\n");
				scanf("%s",p[i]->name);
				getchar();
		}
		for(i=0;i<N;i++)
		{
				printf("please enter choose people number.\n");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1:(p[0]->count)++;break;
					case 2:(p[1]->count)++;break;
					case 3:(p[2]->count)++;break;
					default:printf("this ticker error!");break;
	        	}
		}
		compare(p);
		return 0;
}
void compare(psEle q)
{
		int i=0,j;
		for(j=i;j<=2;j++)
		{
			if((q[i]->count) < (q[j]->count))
				{
						i = j;
				}
		}
		printf("%s%d",q[i]->name,q[i]->count);
}
