#include"save.h"
int stu_Save(pStu pHead,FILE *fd)//保存函数
{
		int count=0;
		pStu ptmp = pHead->next;
		while(ptmp!=NULL)
		{
				count++;
		 	 	fwrite(ptmp,sizeof(sStu),1,fd);
				ptmp = ptmp->next;
		}
		return count;

}
int Save (pList ppp)//主函数的入口
{
		int count=0;
		FILE *fp=NULL;
		fp = fopen("student.txt","w+");//保存到文件中
		if(NULL==fp)
		{
				printf("文件打开失败.\n");
				exit(-1);
		}
		ppp->pStu_Save = stu_Save;//调用结构体函数指针
		count = ppp->pStu_Save(ppp->head,fp);//根据返回值判断是否保存
		if(count!=0)
		{
			printf("保存成功.\n");
		}
		fclose(fp);
		return 0;
}
