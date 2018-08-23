#include<stdio.h>
int judge_str();
char a[100]={0};
int size;
int main()
{
	int m;
	printf("请输入字符串:");
	scanf("%s",a);
	size=(int)strlen(a);
//	printf("%d",size);
	m=judge_str();
	if(m==1)
	{
		printf("是回文");
	}
	else
	{
		printf("不是回文");
	}
}
int judge_str()
{
//	printf("%d",size);
	int i=0;
//	for(i=0;i<(size/2);i++)
//	{
		int k=0;

		if(a[0]==a[size-1])
		{
			while(a[i]==a[size-1-i]&&(i<size/2&&i>=0))
			{
				i++;
				k++;
				printf("%d\n",k);
			}

//			break;
		}
		else
		{
			return 0;

		}

//	}
	if(k==size/2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




