#include"save.h"
void open_file(pStu pHead,pList plist)
{
		FILE *fp;
		fp = fopen("a","w");
		plist->pStu_Save = save_chain;
		plist->pStu_Save(pHead,fp);		
		fclose(fp);	

		fp = fopen("a","r");
		plist->pStu_Save = read_chain;
		plist->pStu_Save(pHead,fp);
		fclose(fp);		
		
		
}
int save_chain(pStu pHead,FILE *fp)
{
		pStu p = pHead->next;
		int len=sizeof(struct student);
		while(p != NULL)
		{
				fwrite(p,1,len,fp);
				p = p->next;
		}

}
int read_chain(pStu pHead,FILE *fp)
{
		pStu p ;
		pStu pTemp;
		pTemp =pHead;
		int flen,i;
		fseek(fp ,0 ,SEEK_END);
		flen = ftell(fp);
		rewind(fp);
		int len=sizeof(struct student);
		for(i=0;i<flen;i+=len)
		{
				
				chain_init(&p);
				fread(p,1,len,fp);
				pTemp->next = p;
				pTemp = p;
		}
		

}
