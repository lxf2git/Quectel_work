#include"ten2two.h"
void ten2two()
{
		sStack skt;
		int data;
		int mod,ss;
		printf("please enter need change digit:\n");
		scanf("%d",&data);
		init_n(&skt);
		while(data!=0)
		{
				mod = data%2;
				push(&skt,mod);
				data =data/2;
		}
		while((pop(&skt,&ss))!=EMPTY)
		{
				printf("%d ",ss);
		}
		printf("\n");

}
void ten2four()
{
		sStack skt;
		int data;
		int mod,ss;
		int sum=0,i=0;
		printf("please enter need change digit:\n");
		scanf("%d",&data);
		init_n(&skt);
		while(data!=0)
		{
				mod = data%4;
				push(&skt,mod);
				data =data/4;
		}
		while((pop(&skt,&ss))!=EMPTY)
		{
				printf("%d ",ss);
		}
		printf("\n");

}
void ten2eight()
{
		sStack skt;
		int data;
		int mod,ss;
		int i=0,sum=0;
		printf("please enter need change digit:\n");
		scanf("%d",&data);
		init_n(&skt);
		while(data!=0)
		{
				mod = data%8;
				push(&skt,mod);
				data =data/8;
		}
		while((pop(&skt,&ss))!=EMPTY)
		{
				printf("%d ",ss);	
		}
		printf("\n");
}
void ten2sixth()
{
		sStack skt;
		int data;
		int mod,ss;
		printf("please enter need change digit:\n");
		scanf("%d",&data);
		init_n(&skt);
		while(data!=0)
		{
				mod = data%16;
				push(&skt,mod);
				data =data/16;
		}
		while((pop(&skt,&ss))!=EMPTY)
		{
				printf("%x ",ss);
		}
		printf("\n");
}
int main()
{
		int choose;
		printf("请输入你要转换的类型:\n1.二进制\n2.四进制\n3.八进制\n4.十六进制\n");
		scanf("%d",&choose);
		switch(choose)
		{
				case 1:ten2two();break;
				case 2:ten2four();break;
				case 3:ten2eight();break;
				case 4:ten2sixth();break;
				default:printf("输入有错.\n");break;
		}
}
