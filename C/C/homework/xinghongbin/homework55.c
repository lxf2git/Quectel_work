#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2
typedef struct student
{
		char * name;
		int age;
		char gender;
		int id;
}*pStu;
void put_file(pStu p);
void disk(pStu p);
struct student *getmemory();
void input(pStu p);
void creatememory(void **p,int size);
void get_file(pStu p);
int main()
{
		pStu p=NULL;
		p=getmemory();

		input(p);
		put_file(p);

		get_file(p);
		printf("%s\n",p->name);	
		printf("%d %c %d\n",p->age,p->gender,p->id);
		return 0;
		

}
void creatememory(void **p,int size)
{
		*p=malloc(size);
		if(*p==NULL)
		{
				printf("memroy error\n");
				exit(-1);
		}
}
struct student *getmemory()
{
		int i;
		pStu p=	NULL;
		creatememory((void**)&p,N*sizeof(struct student));
		for(i=0;i<N;i++,p++)
				creatememory((void **)&p->name,2);
		p-=	N;
		return p;
}
void input(pStu p)
{
		int i;
		for(i=0;i<N;i++,p++)
		{
				printf("name age gender id\n");
				scanf("%s%d",p->name,&p->age);
				getchar();
				scanf("%c%d",&p->gender,&p->id);
		}



}
/*
void disk(pStu p)
{
		int i;
		for(i=0;i<N;i++,p++)
				form( p);
}*/
void put_file(pStu p)
{
		FILE *fp;
		fp=fopen("a","a");
		if(fp==NULL)
		{
				printf("file error \n");
				exit(-1);
		}
//		fseek(fp,0,SEEK_SET);
		fwrite(p,1,sizeof(struct student),fp);
//		fwrite("\n",1,1,fp);
		fclose(fp);

}
void get_file(pStu p)
{
		FILE *fp;
		fp=fopen("a","r");
		if(fp== NULL)
		{
				printf("file error\n");
				exit;
		}
		fread(p,1,sizeof(struct student),fp);
		fclose(fp);

}
