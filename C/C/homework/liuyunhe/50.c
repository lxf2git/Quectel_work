#include<stdio.h>
#include<stdlib.h>
struct student
{
		char *name;
		int age;
}*p;
int main()
{
		int i;
		int n;
		int max=0;
		printf("输入人数\n");
		scanf("%d",&n);
		p=(struct student *)malloc(n*sizeof(struct student));
		for(i=0;i<n;i++)
		{
				p[i].name=(char*)malloc(n*sizeof(char));
				printf("输入第%d位的名字 年龄\n",i+1);
				scanf("%s%d",p[i].name,&p[i].age);
				if(max<p[i].age)
				{
						max=p[i].age;
				}
		}
		for(i=0;i<n;i++)
		{
				if(p[i].age==max)
				{
						printf(" 最大年龄的人信息\n");
				 		printf("name=%s\n age=%d\n",p[i].name,p[i].age);
				}
		}
free(p);
p=NULL;

}
