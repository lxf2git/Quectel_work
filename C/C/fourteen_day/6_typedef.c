#include<stdio.h>
 /*
   typedef char * CH ;
  *1 声明  char * CH;
   2 typedef + 声明  typedef char * CH；		
  * */
int add(int a,int b)
{
	return a+b;
}
/*	1  int (*PFUN)(int,int);
 *  2   typedef int(*PFUN)(int,int);
 * */
 
typedef int(*PFUN)(int,int);//int (*)(int,int);
void func(PFUN p,int m,int n)//int (*p)(int,int);
{
	int ret = p(m,n);
	printf("result:%d\n",ret);
}
int main()
{
	int a=10,b=20;	
	func(add,a,b);

	return 0;

}



