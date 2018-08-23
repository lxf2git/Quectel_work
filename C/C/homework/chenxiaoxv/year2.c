#include<stdio.h>
 
int main()
{
   int a; 
   printf("输入1到7的数字");
   scanf("%d",&a);
   switch(a)
      {	
     	case 1:
		printf("a=monday\n");
		break;
	case 2:
		printf("a=tuesday\n");
		break;
	case 3:
		printf("a=thusday\n");
		break;
	case 4:
		printf("a=wenday\n");
		break;
	case 5:
		printf("a=friday\n");
		break;
	case 6:
		printf("a=sunday\n");
		break;
	case 7:
		printf("a=satday\n");
		break;
       }
	return 0;
}
