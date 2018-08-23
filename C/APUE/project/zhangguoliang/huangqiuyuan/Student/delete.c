#include"main.h"
void del_chain(pStu pHead,int m)
{
          pStu ptmp=NULL;
          FILE *fp=NULL;
          fp=fopen("message.txt","w+");
          for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
         {
			if(ptmp->id!=m)
                  {
			fwrite(ptmp,sizeof(struct student),1,fp);
		  }
         }
                  fclose(fp);
          printf(" 冊除成功！\n");
}
/*void del_chain(int m)
{
	FILE *fp=NULL;
	fp=fopen("message.txt","r");
	int ret;
	pStu pnew=NULL;
	pStu pnew1=NULL;
	init_node(&pnew,sizeof(Stu));
	for(;1;)
	{
		pStu pnew1=(pStu)malloc(sizeof(Stu));
		ret=fread(pnew1,sizeof(Stu),1,fp);
		if(pnew1->id!=m)
		{
		pnew->next=pnew1->next;
		pnew->next=pnew1;
		}
		if(ret==0)
			{break;}
	}
		fclose(fp);
        	write_chain2(pnew);


}*/
