#include<stdio.h>
#include<string.h>

void compositor(char a[],int j)
{
	int i,k,l;
	for(l=0;l<j-2;l++)
	{
		for(i=0;i<j-2;i++)
		{
			//	printf("%c\n",a[i]);		
			if(a[i]=='\n')
					break;
			if(a[i]>a[i+1])
			{
				k=a[i+1];
				a[i+1]=a[i];
				a[i]=k;
			}
				
			
			

		}
	}

}

void delete(char a[],int t)
{
	int i,m;
	char k;
	for(i=0;i<t;i++)
	{
		if(a[i]=='\0')
			break;	
		if(a[i]==a[i+1])
		{
			a[i]='\0';
			for(m=i;m<t;m++)
			{
				k=a[m];
				a[m]=a[m+1];
				a[m+1]=k;

			}
			i--;
		}

	}
	for(i=0;i<t;i++)
	{
		printf("%c",a[i]);
	}

}        
int main()
{
	char a[100],b[100];
	int i,j,k,t,n,m;
	j=1;k=1;
	printf("请输入字符串a：\n");
	for(i=0;i<100;i++)
	{
		scanf("%c",&a[i]);
//		printf("%d     ",i);
		if(a[i]=='\n')
		{
				a[i]='\0';
				
				break;
		}
		j++;
	}
//	printf("%d  \n",j);
	
	compositor(a,j);
	for(i=0;i<j;i++)
	{
		printf("%c",a[i]);
	}   
	printf("\n");

	printf("请输入字符串b：\n");
	for(i=0;i<100;i++)
	{
		scanf("%c",&b[i]);
		if(b[i]=='\n')
		{
				b[i]='\0';
				break;
		}
		k++;
	}
//	printf("%d",k);
	compositor(b,k);

	for(i=0;i<k;i++)
	{
		printf("%c",b[i]);
	}
	printf("\n");
	t=j+k;
//	printf("%d\n",t);
	strcat(a,b);
	puts(a);
	compositor(a,t-2);
	for(i=0;i<t;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	
//	puts(a);
	delete(a,t-1);
	return 0;
}
