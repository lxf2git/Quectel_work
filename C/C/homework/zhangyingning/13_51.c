#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	char name[20];
	int score;
	int math;
	int chinese;
	int english;
}sStudent,*pStu;
void _malloc(void **p,int size)		//开空间函数
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error");
	}
}

void in_put(pStu stu,int man)	//录入函数
{
	int i;
	for(i = 1;i <= man;i++)
	{
		printf("pleas input %d student name\n",i);
		scanf("%s",&stu->name);
		printf("please input math\n");
		scanf("%d",&stu->math);
		printf("please input chinese\n");
		scanf("%d",&stu->chinese);
		printf("please input english\n");
		scanf("%d",&stu->english);
		stu->score = (stu->math + stu->chinese + stu->english);
		stu++;
		printf("______________________\n");
	}	
}

int  paixu(int *p ,int man)	//排序函数，并返回最后一个及格人的成绩
{
	int i, j;
	int a;
	for(i = 0;i < man;i++ )
	{
		for(j = i;j < man;j++)
		{
			if(p[i] < p[j])
			{
				a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
	a = p[man * 7 / 10];
	return a;
}

void average_score(pStu stu,int pscore[], int man)	//求各科平均成绩输出，并返回每科最后及格成绩函数
{
	int *pmath,*pchinese,*penglish;
	_malloc((void**)&pmath,man * sizeof(int));
	_malloc((void**)&pchinese,man * sizeof(int));
	_malloc((void**)&penglish,man * sizeof(int));
	float math_a, chinese_a, english_a, score_a;
	int i;
	for(i = 0;i < man;i++)		//对指针赋值并，对各科求和
	{
		pmath[i]= stu->math;
		math_a += (float)stu->math;
		pchinese[i]= stu->chinese;
		chinese_a += (float)stu->chinese;
		penglish[i]= stu->english;
		english_a += (float)stu->english;
		stu++;
	}
	// 各科平均成绩输出
	printf("average math    %.2f\n",math_a / man);
	printf("average chinese %.2f\n",chinese_a / man);
	printf("average english %.2f\n",english_a / man);
	printf("averagz all     %.2f\n",(math_a + chinese_a + english_a) / 3 / man);
	//保存各科最后及格人的分数
	pscore[0] = paixu(pmath,man);
	pscore[1] = paixu(pchinese,man);
	pscore[2] = paixu(penglish,man);
}

void out_put(pStu stu,int man,int pscore[])		//输出不及格人成绩单函数
{
	int i;
	for(i = 0;i < man;i++)
	{
		if((pscore[0] < stu->math) && (pscore[1] < stu->chinese) && (pscore[2] < stu->english))
		{
				;
		}
		else
		{
		    printf("_____________________\nname %s\n",stu->name);
			if(pscore[0] < stu->math)
			{
				printf("math     %d\n",stu->math);
			}
			else
			{
				printf("math     %d  fail\n",stu->math);
			}
			if(pscore[1] < stu->chinese)
			{
				printf("chinese  %d\n",stu->chinese);
			}
			else
			{ 
				printf("chinese  %d  fail\n",stu->chinese);
			}
			if(pscore[2] < stu->english)
			{
				printf("english  %d\n",stu->english);
			}	
			else
			{	
				printf("english  %d  fail\n",stu->english);
			}
			printf("all      %d\n_____________________\n",stu->score);
		}
		stu++;
	}
}

int main()
{
	int man;
	int pscore[4];
	pStu stu;
	printf("pleass input people");
	scanf("%d",&man);
	_malloc((void **)&stu,man * sizeof(sStudent));
	in_put(stu,man);
	average_score(stu,pscore,man);
	out_put(stu,man,pscore);

}	
