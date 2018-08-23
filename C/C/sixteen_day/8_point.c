#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int *p;
	int n;	
};

void fun(struct node *s1)
{
	s1->p = malloc(100);
	
}
int main()
{
#if 0
	struct node s;
	s.p = NULL;
	s.n = 9;
	printf("s.p-bf:%p\n",s.p);
	fun(&s);
	printf("s.p-af:%p\n",s.p);
#endif

	struct node a[2];
	a[0].p = NULL;
	a[0].n = 9;
	printf("a[0].p-bf:%p\n",a[0].p);
	fun(a);//&a[0] 
	printf("a[0].p-af:%p\n",a[0].p);

}
