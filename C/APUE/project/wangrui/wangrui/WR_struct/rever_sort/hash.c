#include"rev_sort.h"

void creat_hash_list(FILE *fp,
				char *fname,pMod pmod)
{
	char ch;
	int i = 0;
	int con = 0;//判断读取单结束标志
	char sword[256] = {};//存原始单词
	ch = fgetc(fp);
	while(!feof(fp))
	{
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			convert_char(&ch);//如果大写转为小写
			sword[i] = ch;//存入原数组
			con = 1;
			i++;
		}
		else
		{
			if(con == 1)
			{
				insert_word(fname,pmod,sword);//插入单词
				bzero(sword,256);//清空sword
				con = 0;
				i=0;
			}			
		}
		ch = fgetc(fp);
	}	
}

void insert_word(char *fname,pMod pmod,char *org_word)
{
	pWord pHead = NULL;
	pWord pword = NULL;
	char *new_word = NULL;
	int len;
	int ret;
	get_word(&new_word,&len,org_word);//获取单词
	get_head(&pHead,pmod,new_word,len);//获取冲突链头节点
	pword = judge_repeat(pHead,new_word);
	//判断单词是否重复，返回NULL或重复节点
	if(pword == NULL)	//添加新单词
	{
		insert_new_word(pHead,fname,new_word);
	}
	else	//有重复情况
	{
		insert_old_word(pword->data,fname);
	}
}
void insert_old_word(pData pdh,char *fname)
{
	pData pdata = NULL;
	int con = 0;
	for(pdata = pdh->next;pdata != pdh;pdata = pdata->next)
	{
		if(0 == strcmp(pdata->file_name,fname))
		{
			con = 1;
			pdata->num++;	//相同文件名，次数++
			break;
		}
	}
	if(con == 0)
	{
		pdata = NULL;
		init_data(&pdata);
		creat_memory((void**)&pdata->file_name,(strlen(fname)+1));
		strcpy(pdata->file_name,fname);
		pdata->num++;
		insert_data_back(pdh,pdata);
	}
}
void insert_new_word(pWord pHead,char *fname,char *new_word)
{
	pWord pword = NULL;
	pData pdh = NULL;
	pData pdata = NULL;
	init_word(&pword);
	creat_memory((void**)&pword->chword,(strlen(new_word)+1));
	strcpy(pword->chword,new_word);
	pdh =  pword->data;
	init_data(&pdata);
	creat_memory((void**)&pdata->file_name,(strlen(fname)+1));
	strcpy(pdata->file_name,fname);
	pdata->num++;
	insert_data_back(pdh,pdata);
	insert_word_back(pHead,pword);//尾插
}
void get_word(char **new_word,int *len,char *org_word)
{
	*len = strlen(org_word);
	creat_memory((void **)new_word,(*len+1));
	strcpy(*new_word,org_word);
}
void get_head(pWord *pHead,pMod pmod,char *new_word,int len)
{
	int i,j;
	i = (int)(new_word[0]+new_word[len-1]-194)%26;
	j = len%10;
	*pHead = pmod->mod[i]->_and[j];
}
pWord judge_repeat(pWord pHead,char *new_word)
{
	pWord ptmp = NULL;
	if(pHead->next == pHead)
	{
		return NULL;
	}
	else
	{
		for(ptmp = pHead->next;ptmp != pHead;ptmp = ptmp->next)
		{
			if(0 == strcmp(ptmp->chword,new_word))
			{
				return ptmp;
			}
		}
		return NULL;
	}
}

void convert_char(char *ch)
{
	if(*ch>='A' && *ch<='Z')
	{
		*ch = *ch+32;
	}
}
void insert_data_back(pData pdh,pData pdata)
{
	pdata->prev = pdh->prev;
	pdh->prev->next = pdata;
	pdata->next = pdh;
	pdh->prev = pdata;
}
void insert_word_back(pWord pHead,pWord pword)
{
	pword->prev = pHead->prev;
	pHead->prev->next = pword;
	pword->next = pHead;
	pHead->prev = pword;
}
