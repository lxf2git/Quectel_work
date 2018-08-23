#include<stdio.h>
int main()
{
	int date1,date2,zhi;
	char op;
	printf("请输入两个数值：\n");
	scanf("%d%d",&date1,&date2);
	printf("请输入一个运算符：");
	getchar();
	op=getchar();
	switch(op)
{
	case 43:
	zhi=date1+date2;
	printf("%d\n",zhi);
	break;
	case 45:
        zhi=date1-date2;
        printf("%d\n",zhi);
        break;
	case 42:
        zhi=date1*date2;
        printf("%d\n",zhi);
        break;
	case 47:
        zhi=date1/date2;
        printf("%d\n",zhi);
        break;
	default:
	printf("亲，别闹！\n");
	break;
}	

	return 0;


}
