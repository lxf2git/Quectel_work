#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
		char *name;
		int age;
}*sSt;
void compare(sSt s,int N)
{
		int i,j=0,n=0;
	/*	for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						if(s[i].age>=s[j].age)
						{
								n++;
								if(n==N)
								{
										printf("%s %d\n",s[i].name,s[i].age);
										exit(0);
								}
						}
				}
				n=0;
		}*/
		for(i=0;i<N;i++)
		{
				if(s[0].age<s[i].age)
				{
						s[0].age=s[i].age;
						j=i;
				}
		}
		printf("%s %d\n",s[j].name,s[j].age);
}
int main() 
{
	sSt s;
	int n;
	printf("请输入人数\n");
	scanf("%d",&n);
	s = malloc(n*sizeof(struct Student));
	int i;
	printf("请输入姓名年龄\n");
	for(i=0;i<n;i++)
	{
			s[i].name = (char *)malloc(20*sizeof(char)); 
			scanf("%s%d",s[i].name,&s[i].age);
	}
	compare(s,n);
}
