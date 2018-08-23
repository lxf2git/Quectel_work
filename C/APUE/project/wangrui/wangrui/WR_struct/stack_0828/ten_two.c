#include"stack.h"

int main()
{
	pStack psta;
	creat_memory((void **)&psta,sizeof(sStack));

	int data;
	scanf("%d",&data);

	init_stack(psta);
	
	ten_two(psta,data);
	ten_eight(psta,data);
	ten_sixteen(psta,data);

}
void print_num(pStack psta)
{
	int pop_data;
	while((pop(psta,&pop_data))!=-1)
	{
		if(pop_data>=10&&pop_data<=15)
		{
			printf("%c",pop_data+55);
		}
		else
		{
			printf("%d",pop_data);
		}
	}
	printf("\n");
}

int ten_two(pStack psta,int data)
{
	int mod;
	while(data)
	{
		mod = data%2;
		push(psta,mod);
		data = data/2;
//		printf("data:%d\n",data);
	}
	print_num(psta);
}
int ten_eight(pStack psta,int data)
{
	int mod;
	while(data)
	{
		mod = data%8;
		push(psta,mod);
		data = data/8;
	}
	print_num(psta);
}
int ten_sixteen(pStack psta,int data)
{
	int mod;
	while(data)
	{
		mod = data%16;
		push(psta,mod);
		data = data/16;
	}
	print_num(psta);
}
