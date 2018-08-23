#include<stdio.h>
#include<stdlib.h>

struct Student 
{
	char *name;
	int math;
	int Chinese;
	int English;
};

void pass(struct Student **q1,float ave,int n)
{
	int i,sum_p=0;
	for(i=0;i<n;i++)
	{
		sum_p=q1[i]->math+q1[i]->Chinese+q1[i]->English;

		if(sum_p<ave*0.3)
			printf("不及格学生信息:name:%s math:%d Chinese:%d English:%d\n",q1[i]->name,q1[i]->math,q1[i]->Chinese,q1[i]->English);

	}
}

void sum(struct Student **q,int n)
{
	int i;
	float sum_m=0,sum_C=0,sum_E=0,sum;
	float ave_m,ave_C,ave_E, ave;
	for(i=0;i<n;i++)
	{
		sum_m+=q[i]->math;
		sum_C+=q[i]->Chinese;
		sum_E+=q[i]->English;
	}
	sum=sum_m+sum_C+sum_E;
	ave_m=sum_m/n;
	ave_C=sum_C/n;
	ave_E=sum_E/n;
	ave=sum/n;
	printf("数学平均成绩:%.2f\n",ave_m);
	printf("语文平均成绩:%.2f\n",ave_C);
	printf("英语平均成绩:%.2f\n",ave_E);
	printf("总分平均成绩:%.2f\n",ave);
	pass(q,ave,n);
}

int main()
{
	int num,i;
	printf("输入学生人数:\n");
	scanf("%d",&num);
	struct Student *p[num];
	for(i=0;i<num;i++)
	{
		p[i]=(struct Student *)malloc(sizeof(struct Student));
		p[i]->name=(char *)malloc(20*sizeof(char));
		printf("please input name math Chinese English\n");
		scanf("%s%d%d%d",p[i]->name,&p[i]->math,&p[i]->Chinese,&p[i]->English);
	}
	sum(p,num);
}
