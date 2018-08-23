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
	fp = fopen("save.txt","a+");
	fwrite(&pnew->name,sizeof(pnew->name),1,fp);
	fwrite(&pnew->id,sizeof(pnew->id),1,fp);
	fclose(fp);
	//fp = fopen("save.txt","w+");
	//fclose(fp);
	return 0;

}
