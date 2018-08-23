#include<stdio.h>

int main()
{
	int y,m,d,a;
	printf("输入年月日:\n");
	scanf("%d%d%d",&y,&m,&d);
	if((y%4==0&&y%100!=0)||(y%400==0))
	{
	switch(m)
	{
	case 1:a=d;printf("润年，这是今年第:%d天\n",a);break;
	case 2:a=d+31;printf("润年,这是今年的第:%d\n",a);break;
	case 3:a=d+60;printf("润年，这是今年第:%d天\n",a);break;
	case 4:a=d+91;printf("润年，这是今年第:%d天\n",a);break;
	case 5:a=d+121;printf("润年，这是今年第:%d天\n",a);break;
	case 6:a=d+152;printf("润年，这是今年第:%d天\n",a);break;
	case 7:a=d+182;printf("润年，这是今年第:%d天\n",a);break;
	case 8:a=d+213;printf("润年，这是今年第:%d天\n",a);break;
	case 9:a=d+244;printf("润年，这是今年第:%d天\n",a);break;
	case 10:a=d+274;printf("润年，这是今年第:%d天\n",a);break;
	case 11:a=d+305;printf("润年，这是今年第:%d天\n",a);break;
	case 12:a=d+335;printf("润年，这是今年第:%d天\n",a);break;
	default:
	printf("error!\n");
    }
    }
else
	switch(m)
    {
	case 1:a=d;printf("不是润年，这是今年第:%d天\n",a);break;
    case 2:a=d+31;printf("不是润年，这是今年第:%d天\n",a);break;
    case 3:a=d+59;printf("不是润年，这是今年第:%d天\n",a);break;
	case 4:a=d+90;printf("不是润年，这是今年第:%d天\n",a);break;
	case 5:a=d+120;printf("不是润年，这是今年第:%d天\n",a);break;
	case 6:a=d+151;printf("不是润年，这是今年第:%d天\n",a);break;
	case 7:a=d+181;printf("不是润年，这是今年第:%d天\n",a);break;
	case 8:a=d+212;printf("不是润年，这是今年第:%d天\n",a);break;
	case 9:a=d+243;printf("不是润年，这是今年第:%d天\n",a);break;
	case 10:a=d+273;printf("不是润年，这是今年第:%d天\n",a);break;
	case 11:a=d+304;printf("不是润年，这是今年第:%d天\n",a);break;
	case 12:a=d+334;printf("不是润年，这是今年第:%d天\n",a);break;
	default:
	printf("error\n");
	}
    return 0;
}
