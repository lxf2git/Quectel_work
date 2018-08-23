#include<stdio.h>

int main()
{
	int data1,data2,sum;
	char op;
	printf("please input data1 op data2 \n");
#if 0
	scanf("%d",&data1);
	getchar();
	scanf("%c",&op);
	getchar();
	scanf("%d",&data2);
#endif
	scanf("%d%*c%c%d",&data1,&op,&data2);//%*c <==> getchar
	//scanf("%d%c%d",&data1,&op,&data2);

	switch(op)
	{
			
		case '+':sum=data1+data2;printf("%d %c %d =%3d \n",data1,op,data2,sum);break;
		case '-':sum=data1-data2;printf("%d %c %d =%3d \n",data1,op,data2,sum);break;
		case '*':sum=data1*data2;printf("%d %c %d =%3d \n",data1,op,data2,sum);break;
		case '/':sum=data1/data2;printf("%d %c %d =%3d \n",data1,op,data2,sum);break;
		default:printf("input error\n");break;
	}

}
