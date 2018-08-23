#include"load.h"

void load(pNode p)
{
	FILE *fp=NULL;	
	fp = fopen("student.txt","r");
	while(p != NULL)
	{
		fread(p,sizeof(struct node),1,fp);
		p = p->next;
	}
	fclose(fp);
	

}
