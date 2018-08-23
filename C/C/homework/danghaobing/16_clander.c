#include<stdio.h>
int run(int year);
void day(int l,int nd,int year);
int main()
{
    int year,month,i,nd=0;
    scanf("%d%d",&year,&month);
    for(i=1900;i<=year;i++)
    {
		if(i==1900)
				nd=0;
		else if(run(i)==1)
        {
            nd=nd+366;
        }
        else
            nd=nd+365;
    }
    int r,l;
    r=run(year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    switch(month)
    {
        case 1:
        {
            l=31;break;}
        case 2:
        {nd=nd+31;
            l=28+r;
            break;}
        case 3:
        {nd=nd+r+59;
            l=31;break;}
        case 4:
        {nd=nd+r+90;
            l=30;break;}
        case 5:
        {nd=nd+r+120;
            l=31;break;}
        case 6:
        {nd=nd+r+151;
            l=30;break;}
        case 7:
        {nd=nd+r+181;
            l=31;break;}
        case 8:
        {nd=nd+r+212;
            l=31;break;}
        case 9:
        {nd=nd+r+243;
            l=30;break;}
        case 10:
        {nd=nd+r+273;
            l=31;break;}
        case 11:
        {nd=nd+r+304;
            l=30;break;}
        case 12:
        {nd=nd+r+334;
            l=31;break;}            
    }
    day(l,nd,year);
	printf("\n");
}
void day(int l,int nd,int year)
{

    int b,s,h=0,x;
    x=nd%7;
//	printf("x:%d run:%d",x,run(year));
	if(x==6)
		x=-1;
	if(year%400==0)
	{
		s=7;	
	}
	else
			s=0;
 		for(b=-1-x+run(year)-s;b<l;)
 			   {
					h++;
					b++;
					if(b>0)
					{
					printf("%2d  ",b);
					}
					if(b<=0)
					printf("    ");
					if(h%7==0)
					printf("\n");
 			   }
}

int run(int year)
{
	
    if(year%4==0&&year%100!=0||year%400==0)
    { 
        return 1;
    }
    
    else return 0;
}
