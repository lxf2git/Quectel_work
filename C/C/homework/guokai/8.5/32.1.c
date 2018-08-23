#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char a[N],b[N];
	int i,j,m=0,n=0,k,x,y,z,max=0,sta,end;
	scanf("%s",a);
	scanf("%s",b);
	//printf("%s\n%s\n",a,b);
	x=strlen(a);
	y=strlen(b);
	//printf("%d %d",x,y);
	for(i=0;i<x;i++)
	{	
//		printf("a:%c ",a[i]);
		for(j=0;j<y;j++)
		{
//			printf("b:%c ",b[j]);
			if(a[i]==b[j])
			{
				n=1;
				m=j;
				for(k=1;k<(x-i)&&k<(y-j);k++)
				{
						if(a[k+i]==b[j+k])
						{
							n++;
							z=j+k;
						}
						else
								break;
				}
			}	
	  		if(max<n)
			{
				max=n;
				sta=m;
				end=z;
				n=0;
			}
		}
	}
//	printf("sta:%d end:%d",sta,end);

		printf("最大公共字串:\n");
	  for(j=sta;j<end+1;j++)
		  printf("%c",b[j]);
 	printf("\n");
return 0;	
}
