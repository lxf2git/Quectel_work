#include<stdio.h>

int main()
{
	int data1,data2,d;
	char op;
	printf("Intput data1 data2 op\n");
	scanf("%d%d",&data1,&data2);
	getchar();
	scanf("%c",&op);
	switch(op)
{
	case 43 : d=data1+data2; printf("d=%d\n",d); break;
	case 45 : d=data1-data2; printf("d=%d\n",d); break;
	case 42 : d=data1*data2; printf("d=%d\n",d); break;
	case 47 : d=data1/data2; printf("d=%d\n",d); break;
	default  :  printf("ERROR!\n"); break;
}	
	return 0;
}
