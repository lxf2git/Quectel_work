#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mysort(char **str,int n);


int main()
{
	int n;
	int i,k;
	printf("please input the number of str:\n");
	scanf("%d",&n);
	//printf("plense input the word of str:\n");
	//scanf("%d",&k);
	char *str[n];
	for(i=0;i<n;i++)
	{
		str[i]=(char *)malloc(50*sizeof(char));

	}
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);
	}
	mysort(str,n);



}




void mysort(char **str,int n)
{
	int i,j,t=0;
	int m,count[50],b=0,c=0;
	char *a[n],*p;
	printf("各字符串长度:\n");
	for(i=0;i<n;i++)
	{
		a[i]=(char *)malloc(50*sizeof(char));

	}
		p=(char *)malloc(50*sizeof(char));
	for(i=0;i<n;i++)
	{
		count[i]=strlen(str[i]);
		t=0;
		for(j=count[i]-1;j>=count[i]/2;j--)
		{	
			a[i][t]=str[i][j];
			t++;
			if(j==count[i]/2)
			{
				a[i][t]='\0';
			}
		}
		printf("%d\n",count[i]);
	}
	printf("提取尾字母:\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
		
	}
		//printf("%s\n",a);
		for(c=0;c<n;c++)
		{
		for(i=0;i<n;i++)
		{
			m=strlen(a[i]);
			for(j=0;j<m;j++)
			{
				
				if(j==b&&a[i][b]<a[i+1][b])
				{
					p=a[i];
					a[i]=a[i+1];
					a[i+1]=p;
					p=str[i];
					str[i]=str[i+1];
					str[i+1]=p;
					

				}
				if(a[i][b]==a[i+1][b]&&a[i][b+1]<a[i+1][b+1])
				{
					p=a[i];
					a[i]=a[i+1];
					a[i+1]=p;
					p=str[i];
					str[i]=str[i+1];
					str[i+1]=p;
				}

			}

		}
		}
	printf("尾字母换序后:\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
	printf("############################\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%s\n",str[i]);
	}

}
