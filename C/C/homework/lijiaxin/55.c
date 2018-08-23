#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
typedef struct Student
{
		char name[20];
		char age[3];
		char sex;
		char id[20];
}sStu;
int main()
{
		int i;
		FILE *fp;
		char ch = '\n';
		sStu  pp[N];
		bzero(&pp,N*sizeof(sStu));
		fp = fopen("c.txt","w+");
		if(fp==NULL)
		{
				printf("fopen error!\n");
				exit(-1);
		}
		for(i=0;i<N;i++)
		{
				scanf("%s",pp[i].name);
				scanf("%s",pp[i].age);
				getchar();
				scanf("%c",&pp[i].sex);
				scanf("%s",pp[i].id);
				fwrite(&pp[i],1,sizeof(sStu),fp);
				fputc(ch,fp);
		}
		return 0;
	}
