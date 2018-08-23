#include"stack.h"
#include"fun.h"

int menu(pStack ps,int data);

int main()
{
	int data;
	sStack sta;
	init_stack(&sta);
	printf("please input:");
	scanf("%d",&data);
	menu(&sta, data);
	if(sta.bottom!=NULL)
	{
		free(sta.bottom);
		sta.bottom=NULL;
	}
	return SUC;
}

int menu(pStack ps,int data)
{
	int way;
	do
	{
		printf("please chooose change way:\n");
		printf("********0:E X I T*********\n");
		printf("********1:10--->2*********\n");
		printf("********2:10--->16********\n");
		printf("********3:10--->8*********\n");
		scanf("%d",&way);
		switch(way)
		{
			case 0:
				return SUC;
				break;
			case 1:
				fun(ten_two,ps,data);
				break;
			case 2:
				fun(ten_sixteen,ps,data);
				break;
			case 3:
				fun(ten_eight,ps,data);
				break;
			default:
				break;
		}
	}while(way>=1&&way<=3);
	return FULL;
}
