#include"main.h"
int main(int argc,char *argv[])
{

	pFirst pfirst;
	init_first(&pfirst);
	glob_deal(argv[1],pfirst);//传说中的表格初始化
	int x;
	while(1)
	{
		printf("1 find word\n");
		printf("0 exit\n");
		scanf("%d",&x);
		if(x==1)
		look(pfirst);
		else if(x==0)
		break;
		else
				printf("choose error! please choose again\n");
	}
	return 0;
}
