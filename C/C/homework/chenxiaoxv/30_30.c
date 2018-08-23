#include<stdio.h>
#include <string.h>

void fan(char arr[])
{
	int i,n=0;
	for(i=0;/*10!=arr[i-1]*/;i++)
	{
		scanf("%c",&arr[i]);
		if(arr[i]==10)
			break;
	}
	arr[i]='\0';
}
void first(char arr[])
{		
	int i,j;
	char temp;
		for(i=0;i<strlen(arr)-1;i++)
		{
			for(j=i+1;j<strlen(arr);j++)
			{
				if(arr[i]>arr[j])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
}
void second(char arr[])
{
	int i,j,g,f=0;
	char temp;
	for(i=0;i<strlen(arr);i++)
	{
		for(j=i+1;j<strlen(arr);j++)
		{
			if(arr[i]==arr[j])
			{
				
				for(g=j;g<strlen(arr);g++)
				{
					arr[g]=arr[g+1];
				}
				j--;
			}
		}
	}

}
int main()
{
	int n1,n2,s;
	char a[500]={0},b[500]={0};
	printf("input1:");
	fan(a);
	printf("input2:");
	fan(b);
	first(a);
	puts(a);

	first(b);
	puts(b);
	strcat(a,b);
	puts(a);
	first(a);
	puts(a);
	second(a);
	puts(a);

return 0;
}


