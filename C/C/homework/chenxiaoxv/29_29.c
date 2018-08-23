#include<stdio.h>

void fan(char arr[])
{
	int i,j=0,m=0,z=0,h;
	for(i=0;;i++)
	{
		scanf("%c",&arr[i]);
		if(arr[i]>=65&&arr[i]<=90||arr[i]>=97&&arr[i]<=122)
		j++;//character
		else if(arr[i]==32)
		m++;//word
		else if(arr[i]==46)
		{
			z++;			//line
		}	
		for(h=0;h<=i;h++)
		{
    	 if(arr[h]==10&&arr[h+1]==10)
			{
			m=m+z;
			printf("character:%d",j);
			printf("word:%d",m);
			printf("line:%d",z);
						

	
			}
		}
	}
}
int main()
{
	char a[502];
	printf("input:");
	fan(a);
return 0;
}















