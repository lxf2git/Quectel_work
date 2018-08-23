#include<stdio.h>
/*	int(*pf[3])(char,int);//函数指针数组 本质是数组
	pf[0] pf[1]  pf[2]
*/

int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}

void fun(int(*p)(int,int),int m,int n)
{
	int ret;	
	ret = (*p)(m,n);
	printf("result:%d\n",ret);
}

int main()
{
		int i;
		int (*pf[2])(int,int)={add,sub};
		//pf[0] = add;
		//pf[1] = sub;
		for(i=0;i<2;i++)
		{
			fun(pf[i],20,10);		
		}
		return 0;

}
