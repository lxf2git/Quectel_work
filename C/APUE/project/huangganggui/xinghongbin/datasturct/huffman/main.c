#include"main.h"
void translate(pData pTemp,FILE *fp1,pBin pbinary,int length);
void find_same(pData pRoot,int ch,FILE *fp1,pBin pbinary,int* length);
void mid_find(pData pRoot,int ch,FILE *fp1,pBin pbinary,int* length);
void translate_fun(pData pHead_tree);
void readread(pData pRoot);
int main()
{
		pData pHead;
		init_data(&pHead);
		pData pHead_tree;
		read_file(pHead);
		pHead_tree = create_tree(pHead);
//		search_data(pHead_tree->next);
//		find_same(pHead_tree->next);
        translate_fun(pHead_tree->next);
		readread(pHead_tree->next);

		return 0;
}

void translate(pData pTemp,FILE *fp1,pBin pbinary,int length)
{
		static int i = 0;
		int ret;
		if(pTemp != NULL)
		{

				translate(pTemp->parent,fp1,pbinary,length);
						if(pTemp->sign == 1)
						{
								printf("1");
//								fputc('1',fp1);
								pbinary->bin<<=1;
								pbinary->bin|=0x01;
								i++;
						}
						if(pTemp->sign == 2)
						{
								printf("0");
//								fputc('0',fp1);
								pbinary->bin<<=1;
								pbinary->bin|=0x00;
								i++;
						}
						if((i == 8)||((length == 0)&&(pTemp->lc ==NULL && pTemp->rc == NULL)) )
						{
								fwrite(&pbinary->bin,1,1,fp1);
								pbinary->tailbin = i;
								printf("\ni:%d\n",i);
								printf("\ntialbin:%d\n",pbinary->tailbin);
								i=0;
								(pbinary->char_num)++;
								pbinary->bin&=0x00;
								if(i != 8)
										return;
						}
		}
		
}

void translate_fun(pData pHead_tree)
{
		int length;
		int ch;
		sBin binary;
		binary.char_num = 0;
		binary.tailbin = 0;
		FILE*fp1;
		fp1 = fopen("b","w");
		if(fp1 == NULL)
		{
				perror("b");
				exit(-1);
		}
		fseek(fp1,sizeof(sBin),SEEK_CUR);
		FILE *fp;
		fp = fopen("a","r");
		if(fp == NULL)
		{
				perror("a");
				exit(-1);
		}
		fseek(fp,0,SEEK_END);
		length = ftell(fp);
		rewind(fp);
		printf("length%d\n",length);
		while((ch=fgetc(fp)) != EOF)
		{
				find_same(pHead_tree,ch,fp1,&binary,&length);
				if(length == 0)
				{
						rewind(fp1);
						fwrite(&binary,sizeof(sBin),1,fp1);
						
				}
		}
		fclose(fp);
		fclose(fp1);
}
void find_same(pData pRoot,int ch,FILE *fp1,pBin pbinary,int *length)
{
		mid_find(pRoot,ch,fp1,pbinary,length);

		
}
void mid_find(pData pRoot,int ch,FILE *fp1,pBin pbinary,int *length)
{
		if(pRoot->lc != NULL)
				mid_find(pRoot->lc,ch,fp1,pbinary,length);
		if(pRoot->lc ==NULL && pRoot->rc == NULL)
				if(pRoot->data == ch)
				{
						(*length)--;
						if(ch == 10)
								printf("\\n,length:%d:",*length);
						else
								printf("%c,length:%d:",ch,*length);
						translate(pRoot,fp1,pbinary,*length);
						printf("\n");
						return;
				}
		if(pRoot->rc != NULL)
				mid_find(pRoot->rc,ch,fp1,pbinary,length);
}

void readread(pData pRoot)
{
		sBin binary;	
		FILE *fp;
		int ch;
		pData pTemp=pRoot;
		fp = fopen("b","r");
		if(fp == NULL)
		{
				perror("b");
				exit(-1);
		}
		fread(&binary,sizeof(sBin),1,fp);
		printf("char_num:%d tailbin:%d\n",binary.char_num,binary.tailbin);		
		while( (fread(&(binary.bin),1,1,fp)) != 0)		
		{
			pTemp = search_data(pTemp,&binary,pRoot);
		}
		fclose(fp);
}

