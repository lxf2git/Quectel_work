#include"main.h"
#include"rili.h"
void paixu();
void space(int i);

int main()
{ 	
	int a,m,n,k=0,nian,yue,ri=1,zhouji,x,i,l;
	printf("请输入 年 月 \n");
	scanf("%d%d",&nian,&yue);
	k =  rili(nian,yue,ri);
	m=(nian-1900)/4;
	n=(nian-1900)/100;
	x=(nian-1900)*365+m-n+k+1;
	zhouji = x%7;
	if(zhouji==0)
	zhouji=7;
	printf("这月一号是周%d\n",zhouji);
	if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
	{
		l=32;
 	}
	else if(yue==2)
		{
			l=29;			
		}
	else 
	{		
		l=31;
	}
	switch(zhouji)
	{
		case 1 : paixu();
			printf("  %d   ",1);
			 for(a=2,i=2;i<l;i++,a++)
			{	space(i);
				if(i>9)
				printf("  %d ",i);
				else
				printf(" %d  ",i);
				if(i==8)
				printf("  ");
				if(i==2||i==4||i==3||i==5||i==6)
				printf(" ");
				if(i==7)
				printf("\n");
				if(a>7)
				{
					if(a%7==0)
					printf("\n");
				}
			} printf("\n");  break;
		case 2 : paixu();
			printf("       %d    ",1);
			 for(a=3,i=2;i<l;i++,a++)
			{	space(i);
				if(i==9||i==8)
				printf(" ");
				if(i>7)
				printf("  %d ",i);
				else
				printf(" %d   ",i);
				if(i==6)
				printf("\n");
				if(a>7)
				{
					if(a%7==0)
					printf("\n");
				}
			} printf("\n"); break;
		case 3 : paixu();
			printf("            %d   ",1);
			for(a=4,i=2;i<l;i++,a++)
			{	space(i);
				if(i==6||i==9)
				printf(" ");
				if(i>7)
				printf("  %d ",i);
				else
				printf(" %d   ",i);
				if(a%7==0)
				printf("\n");
			} printf("\n"); break;
		case 4 : paixu();
			printf("                %d    ",1);
			for(a=5,i=2;i<l;i++,a++)
			{	space(i);
				if(i>9)
				printf("  %d ",i);
				else
				printf(" %d  ",i);
				if(i==7||i==5)
				printf("  ");
				if(i==2||i==8)
				printf(" ");
				if(a%7==0)
				printf("\n");
			} printf("\n"); break;
		case 5 : paixu();
			printf("                      %d    ",1);
			for(a=6,i=2;i<l;i++,a++)
			{	space(i);
				if(i>9)
				printf("  %d ",i);
				else
				printf(" %d  ",i);
				if(i==2||i==6||i==8||i==7||i==5)
				printf(" ");
				if(i==4)
				printf("  ");
				if(a%7==0)
				printf("\n");
			} printf("\n"); break;
		case 6 : paixu();
			printf("                           %d    ",1);
			for(a=7,i=2;i<l;i++,a++)
			{	space(i);
				if(i>9&&i!=10&&i!=17&&i!=24)
				printf("  %d ",i);
				else
				printf(" %d  ",i);
				if(i==3||i==4)
				printf("  ");
				if(i==8||i==6||i==7)
				printf(" ");
				if(a%7==0)
				printf("\n");
				
			} printf("\n"); break;
		case 7 : paixu();
			printf("                               %d    ",1);
			for(a=0,i=2;i<l;i++,a++)
			{	space(i);
				if(a>1&&a%7==0)
				printf("\n");
				if(i==2||i==6)
				printf("  ");
				if(i==4||i==2)
				printf(" ");
				if(i>9)
				printf("  %d ",i);
				else
				printf(" %d  ",i);
			} printf("\n"); break;
	}
	return 0;
}
void paixu()
{	
	char week[]={"Mon  Tue  Wed  Thu  Fri  Sat  Sun"};
	printf(" %s\n",week);	
}
void space(int i)
{
	if(8==i&&9==i&&12==i)
	{	
		printf(" ");
	}	
}

