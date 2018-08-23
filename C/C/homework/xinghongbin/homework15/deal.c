#include"main.h"
void deal(int a)
{
		int i,s=0,j=0;
		if((a>99)&&(a<501))
				for(i=1;i<a;i++)
						if(a%i==0)
						{
								
							//	printf("a");
								printf(" %d",i);
								s=s+i;
								j++;
						}
		printf("\ntotal:%dnum:%d  \n",j,s);
}
