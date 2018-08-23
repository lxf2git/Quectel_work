#include<stdio.h>
/*int a;
 *int *p=&a;  char *ch; float * f; 
 *函数指针：本质是指针 存函数入口地址 指向一类函数
  1、定义
  2、赋值
  3、调用
 * */
int add(int a,int b)
{
	return a+b;
}
int div(int a,int b)
{
	return a-b;
}

int main()
{
	int ret;	
	//int add(int,int);	
	int div(int,int);
	int (*pf)(int,int)=NULL;//定义
	pf = add;//赋a值
	pf = div;
	ret = (*pf)(4,8);//调用  add(4,8)
	printf("%d\n",ret);
	return 0;

}



