#include<stdio.h>

int main()
{
	int score;
	printf("input a interger:\n");
	scanf("%d",&score);

	switch(score/10)//9 8 7 6
	{
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;		
		case 7:
			printf("C\n");
			break;		
		case 6:
			printf("D\n");
			break;
		default:	
			printf("come on baby\n");
			break;		
	}
	return 0;
}
