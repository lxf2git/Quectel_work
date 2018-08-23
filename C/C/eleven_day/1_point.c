#include<stdio.h>
//二级指针 int a;int *p=&a  int **p;
int main()
{
		
	int a=9;
	int *p=&a;
	int **pp = &p;

	printf("a:%d *p:%d **pp:%d\n",a,*p,**pp);	
	printf("&a:%p p:%p *pp:%p\n",&a,p,*pp);
	return 0;

}
