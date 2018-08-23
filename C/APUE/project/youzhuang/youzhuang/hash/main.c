#include"hash.h"

int main()
{
		pMod mod_5=NULL;
		create_memory((void **)&mod_5,sizeof(sMod));
		create_hash(mod_5);
		find(mod_5);
		//print(mod_5);
		return 0;
}

void create_hash(pMod mod_5)
{
		int x,y;
		int i;
		pAnd and_7=NULL;
		for(i=0;i<5;i++)
		{
				create_memory((void **)&and_7, sizeof(sAnd));
				mod_5->mod[i]=and_7;
		}
		pData p=NULL;
		for(i=0;i<100;i++)
		{
				create_node(&p);
				p->data=i;
				x=p->data%5;
				y=p->data>>3&7;
				if(mod_5->mod[x]->and_[y]==NULL)
				{
						mod_5->mod[x]->and_[y]=p;
				}
				else
				{
						insert_node(mod_5->mod[x]->and_[y],p);
				}
		}
}

void find(pMod mod_5)
{
		int num;
		printf("请输入1～99:\n");
		scanf("%d",&num);
		printf("%d%5=%d %d>>3&7=%d \n",num,num%5,num,num>>3&7);
		output(mod_5->mod[num%5]->and_[num>>3&7]);
		printf("\n");
}

void print(pMod mod_5)
{
		int i,j;
		for(i=0;i<5;i++)
		{
				for(j=0;j<8;j++)
				{
						if(mod_5->mod[i]->and_[j]!=NULL)
						{
								printf(" | ");
								printf("[%d][%d] ",i,j);
								output(mod_5->mod[i]->and_[j]);
						}
				}
		}
		printf("\n");
}
