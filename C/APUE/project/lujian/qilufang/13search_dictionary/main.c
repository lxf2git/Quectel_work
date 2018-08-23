/**************a.out /home/file****************/




#include"main.h"
int main(int argc,char *argv[])
{
	int file_nb;
	int word_nb;
	int i,j;
	char *file_name[M];
	pMod hash;
	hash=malloc(sizeof(sMod));
	for(i=0;i<M;i++)
	{
		file_name[i]=malloc(sizeof(char)*100);
	}		
	file_nb=file_get(file_name,argv[1]);
	hash->mod=malloc(sizeof(pAnd)*file_nb);
	for(i=0;i<file_nb;i++)
	{
		hash->mod[i]=malloc(sizeof(sAnd));	
	}
	word_nb=input_word(hash,file_nb);
	file_open(hash,file_nb,file_name,word_nb);
	func_sort(hash,word_nb,file_nb);	
}
void func_sort(pMod hash,int word_nb,int file_nb)
{
	int in;
	while(1)
	{
		printf("|******<1>***********选择输出查询内容*******|\n");
		printf("|******<2>***********全部输出查询内容*******|\n");
		printf("|******<3>***********退出*******|\n");
		printf("请输入选项：\n");
		scanf("%d",&in);
		switch(in)
		{
			case CHANCE_OUTPUT : chance_output(hash,word_nb,file_nb); break;
			case ALL_OUTPUT : all_output(hash,word_nb,file_nb); break;
			case EXIT : exit(0);
			default : printf("输入错误，请重新输入：\n"); break;
		}
	}
}
