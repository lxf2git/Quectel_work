#include<stdio.h>
#include<stdlib.h>
typedef struct Student_information{
		char name[20];
		int Math_score;
		int Chi_score;
		int Eng_score;
}sSi,*psSi,**ppsSi;
void get_memory(void **q,int z);
void ave(ppsSi pp,int count1);
void print(ppsSi pp1,int count2,float *p1,float in);
int main()
{
		ppsSi num=NULL;
		int count,i;
		printf("please input student number:\n");
		scanf("%d",&count);
		get_memory((void **)&num,count*sizeof(psSi));
		for(i=0;i<count;i++)
		{
				get_memory((void **)(num+i),sizeof(sSi));
				printf("please enter name and three class score:\n");
				scanf("%s%d%d%d",num[i]->name,&num[i]->Math_score,
								&num[i]->Chi_score,&num[i]->Eng_score);
		}
		ave(num,count);
		return 0;
}
void get_memory(void **q,int z)
{
		*q = malloc(z);
		if(NULL==*q)
		{
				printf("malloc error!");
				exit(-1);
		}
}
void ave(ppsSi pp,int count1)
{	
		float sum_M=0,sum_C=0,sum_E=0;
		float ave_M,ave_C,ave_E,ave_all,out;
		int i;
		float *p=NULL;
		get_memory((void **)&p,count1*sizeof(float));
		for(i=0;i<count1;i++)
		{
				sum_M = pp[i]->Math_score+sum_M;
				sum_C = pp[i]->Chi_score+sum_C;
				sum_E = pp[i]->Eng_score+sum_E;
		}
		for(i=0;i<count1;i++)
		{
				p[i] = pp[i]->Math_score + pp[i]->Chi_score
					   	+ pp[i]->Eng_score;
		}
		ave_M = sum_M/count1;
		ave_C = sum_C/count1;
		ave_E = sum_E/count1;
		ave_all = (sum_M + sum_C + sum_E)/count1;
		out = (ave_all*3)/5;
		printf("ave_M:%f ave_C:%f ave_E:%f ave_all:%f \n",
						ave_M,ave_C,ave_E,ave_all);
		print(pp,count1,p,out);
}
void print(ppsSi pp1,int count2,float *p1,float in)
{
		int i;
		for(i=0;i<count2;i++)
		{
				if(p1[i]<in)
				{
				printf("name:%s\n Mat_score:%d\n Chi_score:%d\n Eng_score:%d\n",
								pp1[i]->name,pp1[i]->Math_score,
								pp1[i]->Chi_score,pp1[i]->Eng_score);
				}
		}
}










