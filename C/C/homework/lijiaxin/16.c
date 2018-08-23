#include<stdio.h>
int kongge(int ri);
void riliben(int z,int a,int t);
int main()
{
	 int t,n,i,day[12],a,nian,yue,cha,b;
	 int run=0,ping=0,ri=0;
	 printf("please ent nian yue:");
	 scanf("%d%d",&nian,&yue);
	 if(nian>=1900)
	 {
	 	a=nian%4==0 && nian%100!=0 || nian%400==0 ? 1:0;
		for(cha=1901;cha<=nian;cha++)
		{	
	 		b=cha%4==0 && cha%100!=0 || cha%400==0 ? 1:0;
	 		if(b==1)
	 		{
				 n=29;
				 run++;
			}
			 else
			 {
				 n=28;
				 ping++;
			 }
	//		printf("%d,%d\n",run,ping);
		}

		 switch(yue-1)
		 {
	 		case 12:day[11]=31;
			case 11:day[10]=30;
			case 10:day[9]=31;
			case 9:day[8]=30;
			case 8:day[7]=31;
			case 7:day[6]=31;
			case 6:day[5]=30;
			case 5:day[4]=31;							
			case 4:day[3]=30;
			case 3:day[2]=31;
			case 2:if(a==1) day[1]=29;else day[1]=28;
			case 1:day[0]=31;
		 }
	 }
	 else
	 {
			 printf("error!!!");
	 }
	 for(i=0;i<yue-1;i++)
		 ri=ri+day[i];
	// printf("%d\n",ri);
	 ri=ri+run*366+ping*365;
	// printf("%d\n",ri);
	 t=kongge(ri);
     riliben(yue,a,t);



}
int kongge(int ri)
{
	int t,i;
	t=ri%7;
	if(0==t)
	{
			printf("\n");
	}
	else
	{
			for(i=1;i<=t+1;i++)
			{
					printf("         ");
			}
	}
return t;

}
void riliben(int z,int a,int t)
{
		int i, day;
	switch(z)
	
	 {
	 		case 12:day=31;break;
			case 11:day=30;break;
			case 10:day=31;break;
			case 9:day=30;break;
			case 8:day=31;break;
			case 7:day=31;break;
			case 6:day=30;break;
			case 5:day=31;break;						
			case 4:day=30;break;
			case 3:day=31;break;
			case 2:if(a==1) day=29;else day=28;break;
			case 1:day=31;break;
       }
	for(i=1;i<=day;i++)
	{
		if( 0==((t+1+i)%7))
		{
				printf("   %-3d   \n",i);
		}

		else
		{
				printf("   %-3d   ",i);
		}
		if(i==day)
				printf("\n");
	}

}
