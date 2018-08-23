#include<stdio.h>
struct node
{
	int *p;
	int n;
};

void fun(struct node s1)
{
	int b=99;
	s1.p = &b;
	s1.n = 8;

}
int main()
{
	struct node arr[3];

	struct node s;
	int a=100;
	s.p = &a;
	s.n = 9;
	fun(s);
	printf("%d %d\n",*s.p,s.n);
}
