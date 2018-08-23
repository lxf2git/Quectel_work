#include<stdio.h>
int main()
{	
	printf("请输入3个数：\n");
     int q,w,e,x;
	scanf("%d %d %d",&q,&w,&e);

  	
if ( q>=w&&q>=e&&w>=e) 
   { x=q-e; printf("最大：%d",q);printf("最小：%d",e);printf("差：%d",x);}
else if(q>=e&&q>=w&&e>=w) 
    {x=q-w; printf("最大：%d",q);printf("最小：%d",w);printf("差：%d",x);}                   

else if(w>=q&&w>=e&&q>=e)
    {x=w-e; printf("最大：%d",w);printf("最小：%d",e);printf("差：%d",x);}
else if(w>=e&&w>=q&&e>=q) 
    {x=w-q; printf("最大：%d",w);printf("最小：%d",q);printf("差：%d",x);}
else if(e>=w&&e>=q&&w>=q)
    {x=e-q; printf("最大：%d",e);printf("最小：%d",q);printf("差：%d",x);}
else if  (e>=q&&e>=w&&q>=w) 
     {x=e-w; printf("最大：%d",e);printf("最小：%d",w);printf("差：%d",x);}
 
return 0;
}
