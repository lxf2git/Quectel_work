#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int id;
	char name[20];
}*pNode;
int main()
{
	FILE *fp=NULL;	
	pNode  pnew=(pNode)malloc(sizeof(struct node));	
	pnew->id = 1;
	strcpy(pnew->name,"huxin");
	fp = fopen("save.txt","w+");
	fwrite(pnew,sizeof(struct node),1,fp);
	fclose(fp);
	return 0;

}

