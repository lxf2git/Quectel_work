#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
		char *name;
		int mathage;
		int chineseage;
		int englishage;
		int sum;
}*p;

struct ss
{
		
		int math_S;
		int chinese_S;
		int english_S;
		int sum_S;
}SS;

void ranking(int n)
{
		int i,j,m;
		int *t;
		t=malloc(n*sizeof(int));
#if 1
				for(i=0;i<n-j;i++)
				{
						t[i]=p[i].sum;
				}

				for(j=1;j<n;j++)
				{
						for(i=0;i<n-j;i++)
						{
								if(t[i]>t[i+1])
								{
										m=t[i];
										t[i]=t[i+1];
										t[i+1]=m;
								}
						}
				}
		for(i=0;i<n;i++)
		{
				m=(n*3/10)+((n*3%10)/5);
			//	printf("%d\n",m);
				if(p[i].sum<t[m])
				{
						printf(" 不及格学生信息\n");
				 		printf("name=%s mathage=%d chinses=%d english=%d\n"
					,p[i].name,p[i].mathage,p[i].chineseage,p[i].englishage);
				}
		}
#endif
#if 0
		for(i=0;i<n;i++)
		{
				if(p[i].sum<(((SS.sum_S)/n)*0.3))
				{
						printf(" 不及格学生信息\n");
				 		printf("name=%s mathage=%d chinses=%d english=%d\n"
					,p[i].name,p[i].mathage,p[i].chineseage,p[i].englishage);
				}
		}
#endif

}
void sum(int n)
{
		int i;
		SS.math_S=0;
		SS.chinese_S=0;
		SS.english_S=0;
		SS.sum_S=0;
		for(i=0;i<n;i++)
		{
				p[i].sum=0;
				p[i].name=(char*)malloc(n*sizeof(char));
				printf("输入第%d位的名字 数学成绩 语文成绩 英语成绩\n",i+1);
				scanf("%s%d%d%d",p[i].name,&p[i].mathage,
								&p[i].chineseage,&p[i].englishage);
				SS.math_S+=p[i].mathage;
				SS.chinese_S+=p[i].chineseage;
				SS.english_S+=p[i].englishage;
				p[i].sum =p[i].mathage+p[i].chineseage+p[i].englishage;
				SS.sum_S+=p[i].sum;
		}

}
int main()
{
		int n;
		printf("输入人数\n");
		scanf("%d",&n);
		p=malloc(n*sizeof(struct student));

		sum(n);

		printf("数学总平均成绩=%d\n语文总平均成绩=%d\n英语总平均成绩=%d\n总分平均成绩%d\n",(SS.math_S)/n,(SS.chinese_S)/n,(SS.english_S)/n,(SS.sum_S)/n);
       ranking(n);
	   if(p!=NULL)
	   {
	   free(p);
	   }

return 0;
}
