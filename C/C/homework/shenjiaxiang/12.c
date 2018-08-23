#include<stdio.h>
void chengfa();
int main()
{
	chengfa();
	return 0;
}

void chengfa()
{
	int hang,lie,a;
	for(hang=1;hang<=9;hang++)
		for(lie=1;lie<=hang;lie++)
			{
				a = lie * hang;
				printf("%d*%d=%2d",lie,hang,a);
				 if(lie==hang)
				{
					printf("\n");
				}
				else if(lie<hang)
				{	
						printf(",");
						printf(" ");
				}
			}
}
