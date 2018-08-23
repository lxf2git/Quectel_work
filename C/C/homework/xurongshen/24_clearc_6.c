#include<stdio.h>
#define N 20
#include<string.h>

void clear(char str3[N]);
void aa(char str3[N]);

int main()
{
	char str1[N]={0};
	char str2[N]={0};
	int i;
	printf("请输入一串字符串：");
	for(i=0;i<N;i++)
	{
		scanf("%c",&str1[i]);
		if(str1[i] == 10)
		{
			break;
		}
	}
	printf("输出一串字符串printf：");

	clear(str1);
	return 0;
}

void clear(char str3[N])
{
	int i;
//	char str2[N]={},str4[N]={};
	
	for(i=0;i<N;i++)
	{
		aa(str3);
	}
//				printf("str3:\n");
//	strcat(str4,str3);

//	for(i=0;i<N;i++)
//	{
		printf("%s",str3);
//	}

}
	

void aa(char str3[N])
{
	int i,j;

	for(i=0;i<N;i++)
	{
		if(str3[i] == 'c')
		{
			if(str3[i+1] != '\0')
			{	
			for(j=i;j<N;j++)
			{
				str3[j] = str3[j+1];
			}
			i--;
			}
			else
			{
				str3[i] = '\0';
				break;
			}
		}
	//	str3[i]=str4[i];
//		strcpy(str3,str2);
	}
}
