#include"main.h"
pData create_tree(pData pHead)
{
#if 0
		pData pHead_tree;
		while(pHead->next->next != pHead)
		{
				init_data(&pHead_tree);
				create_tree_unit(pHead_tree,pHead);
				pHead = pHead_tree;

		}
//				show_tree(pHead);
				return pHead;
#endif
		create_huffman(pHead);
		show_tree(pHead);
		return pHead;

		
}
void create_tree_unit(pData pHead_tree,pData pHead)
{
		pData p_tree;
		pData pTemp_bf = pHead->next;
		pData pTemp_af = pTemp_bf->next;

		while((pTemp_bf != pHead) && (pTemp_af != pHead))
		{
			init_data(&p_tree);
			p_tree->lc = pTemp_bf;
			pTemp_bf->sign = 1;
			pTemp_bf->parent = p_tree;

			p_tree->rc = pTemp_af;
			pTemp_af->sign = 2;
			pTemp_af->parent = p_tree;

			p_tree->num = pTemp_bf->num +pTemp_af->num;
			pTemp_bf = pTemp_af->next;
			pTemp_af = pTemp_bf->next;
			insert_chain(pHead_tree,p_tree);


		}

		if((pTemp_bf->next == pHead)&&(pTemp_bf != pHead))
		{
//				p_tree = pTemp_bf;
				insert_chain(pHead_tree,pTemp_bf);
		}



}
void create_huffman(pData pHead)
{
		pData p_tree;
		pData pTemp_bf = pHead->next;
		pData pTemp_af = pTemp_bf->next;
		while(pHead->next->next != pHead)
		{
				init_data(&p_tree);
				p_tree->lc = pTemp_bf;
				pTemp_bf->sign = 1;
				pTemp_bf->parent = p_tree;

				p_tree->rc = pTemp_af;
				pTemp_af->sign = 2;
				pTemp_af->parent = p_tree;
				p_tree->num = pTemp_bf->num +pTemp_af->num;
				delete_chain(pHead,pTemp_bf);
				delete_chain(pHead,pTemp_af);
				insert_chain(pHead,p_tree);
				pTemp_bf = pHead->next;
				pTemp_af = pTemp_bf->next;
		}

}

void show_tree(pData pHead)
{
//		output_chain(pHead);
		printf("tree**************\n");
		pData pTemp =pHead->next;
		while(pTemp != pHead)
		{
				mid_show(pTemp);

				pTemp = pTemp->next;
		}
}
void mid_show(pData pRoot)
{
		if(pRoot->lc != NULL)
				mid_show(pRoot->lc);
//		if(pRoot->lc ==NULL && pRoot->rc == NULL)
//		stat_sign(pRoot);
		if(pRoot->data == -1)
				printf(" root   num:%d sign:%d\n",pRoot->num,pRoot->sign);
		else
				if(pRoot->data == 10)
						printf("char:\\n num:%d sign:%d\n",pRoot->num,pRoot->sign);
				else
						printf("char:%c  num:%d sign:%d\n",pRoot->data,pRoot->num,pRoot->sign);
		if(pRoot->rc != NULL)
				mid_show(pRoot->rc);
}
void stat_sign(pData p)
{
		pData pTemp = p->parent;
		while(pTemp != NULL)
		{
				p->sign = p->sign * 10+pTemp->sign;
				pTemp = pTemp->parent;
		}
		
}

pData search_data(pData pTemp,pBin p,pData pRoot)
		//pData search_data(pData pRoot, pBin p)
{
		int i=0;
		int num =8;
		if(p->char_num == 1)
		{
				num = p->tailbin;
//				printf("ch: %d\n",p->bin);
						p->bin<<=(8-num);
		}
//		int choose;
//		choose = ch-48;
//		if(choose == 1)
//		printf("\nch:%c  char_num:%d num:%d\n",p->bin,p->char_num,num);
		
				for(;i<num;i++)
				{
						
						if((p->bin&0x80) == 0x80)
						{
//								printf("1");
								pTemp = pTemp->lc;
								if(pTemp->lc == NULL && pTemp->rc == NULL)
								{
										printf("%c",pTemp->data);
										pTemp = pRoot;
								}
						}
						else
						{
//										printf("0");
								pTemp = pTemp->rc;
								if(pTemp->lc == NULL && pTemp->rc == NULL)
								{
										printf("%c",pTemp->data);
										pTemp = pRoot;
								}
						}
						p->bin<<=1;
				}
				p->char_num--;
				return pTemp;


}
