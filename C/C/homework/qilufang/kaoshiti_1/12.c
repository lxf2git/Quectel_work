#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int change(char *p,int nb);

/*********运算函数***************/
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int dive(int a,int b)
{
	return a/b;
}

/**********调用运算函数******************/
void func(int (*p)(int ,int),int a,int b)
{
	printf("result:%d\n",p(a,b));
}

/***********主函数*******************/
int main(int argc,char *argv[])
{
	if(argc>2)
	{
		printf("你输入的参数过多!\n");
		exit(-1);
	}
	int ret_1=0,i=0,j,b=0,ret_2=0;
	while(*(argv[1]+i)<58&&*(argv[1]+i)>47)
	{
		i++; b=i;
	}
	ret_1=change(argv[1],b);
	printf("Ret_1:%d\n",ret_1);
//	printf("FUhao:%d\n",*(argv[1]+i));
	ret_2=change(argv[1]+b+1,strlen(argv[1])-b-1);
	printf("Ret_2:%d\n",ret_2);
//	printf("Argc:%d\n",argc);
	switch(*(argv[1]+b))
	{
		case '+' :
			   	func(add,ret_1,ret_2); 	break;
		case '-' :
			   	func(sub,ret_1,ret_2); 	break;
		case '*' :
			   	func(mul,ret_1,ret_2); 	break;
		case '/' :
			   	func(dive,ret_1,ret_2); 	break;
		default :
			   	printf("Input Error!\n"); 	break;
	}
	return 0;
}

/*************数字转换函数***************/
int change(char *p,int nb)
{
	int sum=0,i=0,j=0;
	for(i=0;i<nb;i++)
	{
		sum=sum*10;
		sum+=*(p+i)-48;
	}
	return sum;
}
