#include"yue_shu.h"
/*#include"add.h"*/

int yue_shu(int nu)
{
        int add=0,i=0;
	int geshu=0,yueshu=0;
	do
	{
		yueshu++;
		if(nu%yueshu==0&&nu!=yueshu&&yueshu!=1)
		{
			printf("约数为%d\n",yueshu);
			geshu++;
			add=yueshu+i;
			i=add;
			/*			printf("%d",add);*/
		}
	}while(yueshu<=nu);
	printf("个数为%d\n",geshu);
	printf("和为%d\n",i);
}
