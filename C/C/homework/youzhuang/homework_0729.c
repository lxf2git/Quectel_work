#include<stdio.h>
//--------------------10.% 3 5 7----------
void calculate_357();
//--------------------11.max min----------
void subtraction();
int CalMax(int a,int b,int c);
int CalMin(int a,int b,int c);
//--------------------12.9*9--------------
void nineXnine();
//--------------------13.fish-------------
void fish();

//--------------main()---------------

int main()
{
		printf("\n ----------------10.% 3 5 7--------------\n\n");
		calculate_357();  // 10.% 3 5 7

		printf("\n ----------------11.max min--------------\n\n");
		subtraction();	  // 11.max min

		printf("\n ----------------12.9*9------------------\n\n");
		nineXnine();	  // 12.9*9

		printf("\n ----------------13.fish-----------------\n\n");
		fish();			  // 13.fish
		
		printf("\n");
		return 0;
}

//-------------------10.% 3 5 7-----------------

void calculate_357()
{
		int i,n=0; //n为输出次数 6次一换行
		for(i=1;i<=1000;i++)
		{
				if(i%3==2&&i%5==3&&i%7==1)
				{
						n++;
						printf(" %d",i);
						if(n!=0&&n%6==0)
						{
								printf("\n");
						}
				}
		}
		printf("\n");
}

//-----------------11.max min--------------------

void subtraction()
{
		char ch;
		int a,b,c,max,min;
		printf(" 请输入3个数字：\n ");
	//	scanf("%d%d%d",&a,&b,&c);

		scanf("%d",&a);
		ch=getchar();
		if(ch==10)
		{
				printf(" ");
		}
		scanf("%d",&b);
		ch=getchar();
		if(ch==10)
		{
				printf(" ");
		}
		scanf("%d",&c);

		max=CalMax(a,b,c);
		min=CalMin(a,b,c);
		printf(" %d-%d=%d\n",max,min,max-min);
}

int CalMax(int a,int b,int c)
{
		int max=a;
		if(max<b)
		{
				max=b;
		}
		if(max<c)
		{
				max=c;
		}
		return max;
}
int CalMin(int a,int b,int c)
{
		int min=a;
		if(min>b)
		{
				min=b;
		}
		if(min>c)
		{
				min=c;
		}
		return min;
}

//------------------12.9*9-----------------

void nineXnine()
{
		int i,j;
		for(i=1;i<=9;i++)
		{
				printf(" ");
				for(j=1;j<=i;j++)
				{
						printf("%dX%d=%d  ",j,i,i*j);
						if((i*j)<10)
						{
								printf(" ");
						}
				}
				printf("\n");
		}
}

//-----------------13.fish----------------

void fish()
{
		int i,sum=1;
		for(i=1;i<=5;i++)
		{
				sum=sum*5+1;
		}
		printf(" 他们至少捕了%d条鱼\n",sum);
}
