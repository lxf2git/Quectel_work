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
	fp = fopen("save.txt","r");
	fread(pnew,sizeof(struct node),1,fp);
	printf("%d %s\n",pnew->id,pnew->name);
	fclose(fp);
	return 0;

}
