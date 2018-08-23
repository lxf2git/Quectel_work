#include<stdio.h>
#include<string.h>



void string1(char a[])
{
	int i,j=0,k,n;
	printf("输入第一个字符串\n");
	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		j++;
		if(a[i]==10)
		{
			j--;
			a[i]=0;
			break;
		}
	}
	for(i=0;i<j-1;i++)
	{
		for(k=0;k<j-1-i;k++)
		{
			if(a[k]>a[k+1])
			{
				n=a[k];
				a[k]=a[k+1];
				a[k+1]=n;
			}
		
		}
	}
	for(i=0;i<j;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
}

void string2(char a[])
{
	int i,h=0,k,n;
	printf("输入第二个字符串\n");
	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		h++;
		if(a[i]==10)
		{
			h--;
			break;
		}
	}
	for(i=0;i<h-1;i++)
	{
		for(k=0;k<h-1-i;k++)
		{
			if(a[k]>a[k+1])
			{
				n=a[k];
				a[k]=a[k+1];
				a[k+1]=n;
			}
		}
	}
	for(i=0;i<h;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");	
}

void mix(char a1[],char a2[])
{
	int i,j,n,k,m,s=0;
	strcat(a1,a2);
	printf("%s",a1);
	n=strlen(a1);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a1[j]>a1[j+1])
			{
				m=a1[j];
				a1[j]=a1[j+1];
				a1[j+1]=m;
			}
		}
	}
	/*for(i=0;i<=n/2;i++)
	{
		j=n-1;
		n=a1[i];
		a1[i]=a1[j];
		a1[j]=n;
		j--;
	}*/
	printf("%s",a1);
	//for(i=0;i<n;i++)
	i=0;
	//{
		for(j=1;j<n;j++)
		{
			if(a1[i]==a1[j])
			{
				s++;
				for(k=i;k<n;k++)
				{
					a1[k]=a1[k+1];
				}
				j--;
				i--;
		//printf("1:%d",i);
			}
			i++;
		//printf("2:%d",i);
			if(i==n-s)
			break;
		}
	//}	

/*	for(i=0;i<n-s;i++)
	{
		for(j=1;j<n-s;j++)
		{
			if(a1[i]==a1[j])
			{
				for(k=i;k<n-s;k++)
				a1[k]=a1[k+1];
			}
		}
	}*/
	printf("%s",a1);
}

int main()
{
	char a1[200]={0};
	char a2[100]={0};
	string1(a1);
	string2(a2);
	mix(a1,a2);
	return 0;
}
