#include<stdio.h>
int main()
{
	int a,b,c,d,sum,y;
	printf("请输入年份：");
	scanf("%d",&y);
	if(y%4==0&&y%100!=0||y%400==0)
{
	printf("这是润年！\n");
	printf("请输入月份：\n");
	scanf("%d",&a);
	b=a-1;
	switch(b)
{
	case 11:
	c=335;
	break;
	case 10:
	c=305;
	break;
	case 9:
	c=274;
	break;
	case 8:
	c=244;
	break;
	case 7:
	c=213;
	break;
	case 6:
	c=182;
	break;
	case 5:
	c=152;
	break;
	case 4:
	c=121;
	break;
	case 3:
	c=91;
	break;
	case 2:
	c=60;
	break;
	case 1:
	c=31;
	break;
	case 0:
	c=0;
	break;
	default:
	printf("没有这个月份！\n");
	break;
}
	printf("请输入几号：\n");
	scanf("%d",&d);
	sum=c+d;
	printf("是一年之中的第%d天\n",sum);

}
	else
{
	printf("不是润年！\n");
	printf("请输入月份：\n");
	scanf("%d",&a);
	b=a-1;
	switch(b)
{
	case 11:
        c=334;
        break;
        case 10:
        c=304;
        break;
        case 9:
        c=273;
        break;
        case 8:
        c=243;
        break;
        case 7:
        c=212;
        break;
	 case 6:
        c=181;
        break;
        case 5:
        c=151;
        break;
        case 4:
        c=120;
        break;
        case 3:
        c=90;
        break;
        case 2:
        c=59;
        break;
        case 1:
        c=31;
        break;
	case 0:
	c=0;
	break;
	default:
        printf("没有这个月份！\n");
        break;
}
	printf("请输入几号：\n");
        scanf("%d",&d);
        sum=c+d;
        printf("是一年之中的第%d天\n",sum);

}


	return 0;

}
