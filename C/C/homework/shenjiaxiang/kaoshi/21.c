#include<stdio.h>
#include<string.h>
int main()
{
	int x,i=0,n,b;
	char a[100];
	scanf("%d",&x);
	/*while(1)
	{
		a[i]=x%2+48;
		if(x/2!=0)
		{
			x=x/2;
			i++;
		}
		else
		break;
	}*/
	while(x/2!=0||x%2!=0)//尽量少用多个条件判断，以免弄错
	{
		a[i]=x%2+48;
		x=x/2;
		i++;
	}
	
	a[i]='\0';
	n=strlen(a);
	for(i=0;i<=n-1;i++,n--)
	{
		b=a[n-1];
		a[n-1]=a[i];
		a[i]=b;
	}
	puts(a);
}
