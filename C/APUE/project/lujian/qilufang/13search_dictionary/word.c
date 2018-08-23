#include"main.h"
int input_word(pMod hash,int file_nb)
{
	int in,i,j;
	printf("输入要输入的单词个数：\n");
	scanf("%d",&in);
	char *input[in];
	for(i=0;i<in;i++)
	{
		getmemory((void **)&input[i],sizeof(int)*N);
	}
	printf("输入要查询的%d个单词:\n",in);
	for(i=0;i<in;i++)
	{
		scanf("%s",input[i]);
	}
	for(i=0;i<file_nb;i++)
	{
		hash->mod[i]->an=malloc(sizeof(pData)*in);
		for(j=0;j<in;j++)
		{
			init_data(&hash->mod[i]->an[j],sizeof(sData));
			strcpy(hash->mod[i]->an[j]->word,input[j]);
		}
	}
	return in;
}
void all_output(pMod hash,int word_nb,int file_nb)
{
	int i,j;
	for(i=0;i<file_nb;i++)
	{
		for(j=0;j<word_nb;j++)
		{
			printf("Word:%s    file%d    NB:%d\n",hash->mod[i]->an[j]->word,i+1,
					hash->mod[i]->an[j]->nb);
		}
		printf("\n");
	}
}
void chance_output(pMod hash,int word_nb,int file_nb)
{
	int in;
	while(1)
	{
		printf("|******<1>***********按单词输出查询内容*******|\n");
		printf("|******<2>***********按文件输出查询内容*******|\n");
		printf("|******<3>***********返回*******|\n");
		printf("请输入选项：\n");
		scanf("%d",&in);
		switch(in)
		{
			case CHANCE_OUTPUT : word_output(hash,word_nb,file_nb); break;
			case ALL_OUTPUT : file_output(hash,word_nb,file_nb); break;
			case EXIT : return;
			default : printf("输入错误，请重新输入：\n"); break;
		}
	}
}
void word_output(pMod hash,int word_nb,int file_nb)
{
	int i,j,nb=0;
	char arr[N];
	printf("输入你要查询的单词：\n");
	scanf("%s",arr);
	for(i=0;i<file_nb;i++)
	{
		for(j=0;j<word_nb;j++)
		{
			if(strcmp(arr,hash->mod[i]->an[j]->word)==0)
			{
				printf("Word:%s    file%d    NB:%d\n",hash->mod[i]->an[j]->word,i+1,
					hash->mod[i]->an[j]->nb);
				nb++;
			}
		}
	}
	if(nb==0)
	{
		printf("你输入的单词不存在！\n");
	}	
}
void file_output(pMod hash,int word_nb,int file_nb)
{
	int j,nb=0;
	int in;
	printf("输入你要查询file的序号：\n");
	scanf("%d",&in);
	for(j=0;j<word_nb;j++)
	{
		if(in>file_nb||in<1)
		{
			printf("此文件不存在！\n");
			break;
		}
		printf("Word:%s NB:%d\n",hash->mod[in-1]->an[j]->word,
			hash->mod[in-1]->an[j]->nb);
	}	
}
