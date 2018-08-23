#include"main_st.h"
#include"save.h"
#include"init.h"


int save(pStu phead,FILE * fd)
{
	openfile(&fd);
	save_write(phead, fd);
	fclose(fd);
	return SUC;
}

void save_write(pStu phead, FILE *fp)
{
	pStu ptmp;
	for(ptmp=phead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		if(ptmp->num != 0)
		{
			fwrite(ptmp, sizeof(sStu), 1, fp);
			printf("save_write--->!\n");
		}
	}
}

