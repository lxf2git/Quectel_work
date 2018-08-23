#include"about_money.h"
extern int b[100];
extern long id;
void save(int _sum,long _id)
{
	b[_id]=b[_id]+_sum;
}

void withdraw(int _sum,long _id)
{
	b[_id]=b[_id]-_sum;
}
