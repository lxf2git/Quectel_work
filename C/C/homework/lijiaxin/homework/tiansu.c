#include<stdio.h>

int main()
{
	int n,i,day[12],a,nian,yue,ri;
	printf("please ent nian yue ri:");
	scanf("%d%d%d",&nian,&yue,&ri);
	a=nian%4==0 && nian%100!=0 || nian%400==0 ? 1:0;

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
	 for(i=0;i<yue-1;i++)
			ri=ri+day[i];
	 printf("是%d年的第%d天\n",nian,ri);

	return 0;
}
