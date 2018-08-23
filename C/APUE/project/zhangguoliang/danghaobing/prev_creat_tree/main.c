#include"main.h"
int main()
{
	pTree pStart;
	init_Node(&pStart);
	first_creat(pStart);
	printf("first tree:\n");
	show_first(pStart);
	printf("\nmid tree:\n");
	show_mid(pStart);
	printf("\nlast tree:\n");
	show_last(pStart);
	printf("\n");
}
