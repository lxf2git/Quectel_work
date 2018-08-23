#include"stack.h"
int main()
{
	sStack sta;
	int mod;
	int pop_data;
	init_stack(&sta);//	*bottom top
	int data;//被除数
	printf("please input:\n");
	scanf("%d",&data);	
	while(data!=0)
	{
		 mod = data%2;//余数
		 push(&sta,mod);
		 data = data/2;
	}	

	while((pop(&sta,&pop_data))!=EMPTY)
	{
		printf("%d ",pop_data);
	}
	printf("\n");
	return 0;

}
