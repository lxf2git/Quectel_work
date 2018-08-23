#include<stdio.h>
int main()
{
	int nian,yue,ri,a,b=0,c,d,e;              
	scanf("%d%d%d",&nian,&yue,&ri);
	c=nian%400;
	d=nian%4;
	e=nian%100;
	 if(c==0)
          {
                  b=1;
        }
          else 
	{ if(d==0&&e!=0)
          {
                  b=1;
          }
        else
        {
                b=0;
        }}
	if(b==1)
	{
		switch(yue)
		{
		case 1:
		a=ri;
		break;
		case 2:
		a=31+ri;
		break;
		case 3:
			a=31+29+ri;
		break;
		case 4:
			a=31+29+31+ri;
		break;
		case 5:
			a=31+29+31+30+ri;
		break;
		case 6:
			a=31+29+31+30+31+ri;
		break;
		case 7:
			a=31+29+31+30+31+30+ri;
		break;
		case 8:
			a=31+29+31+30+31+30+31+ri;
		break;
		case 9:
			a=31+29+31+30+31+30+31+31+ri;
		break;
		case 10:
			a=31+29+31+30+31+30+31+31+30+ri;
		break;
		case 11:
			a=31+29+31+30+31+30+31+31+30+31+ri;
		break;
		case 12:
			a=31+29+31+30+31+30+31+31+30+31+30+ri;
		break;
		}
	}
	else
	{
		switch(yue)
		{
			case 1:
				a=ri;
			break;
			case 2:
				a=31+ri;
			break;
			case 3:
				a=31+28+ri;
			break;
			case 4:
				a=31+28+31+ri;
			break;
			case 5:
				a=31+28+31+30+ri;
			break;
			case 6:
				a=31+28+31+30+31+ri;
			break;
			case 7:
				a=31+28+31+30+31+30+ri;
			break;
			case 8:
				a=31+28+31+30+31+30+31+ri;
			break;
			case 9:
				a=31+28+31+30+31+30+31+31+ri;
			break;
			case 10:
				a=31+28+31+30+31+30+31+31+30+ri;
			break;
			case 11:
				a=31+28+31+30+31+30+31+31+30+31+ri;
			break;
			case 12:
				a=31+28+31+30+31+30+31+31+30+31+30+ri;
			break;
		}
	}
	printf("a:%d\n",a);
	printf("b:%d\n",b);
	printf("c:%d\n",c);
	printf("d:%d\n",d);
	printf("e:%d\n",e);
return 0;
}
