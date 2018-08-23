int main()
{
		struct apply_chain *apply_head=NULL;
		struct free_chain   *free_head=NULL;
		struct record_chain *record_head=NULL;
		struct tmp_chain *tmp_head=NULL;

		int apply_mem_size=0;

		appley_head=init_node(sizeof(struct apply_chain));
		free_head  =init_node(sizeof(struct free_chain));
		record_head=init_node(sizeof(struct record_chain));
		tmp_head=init_node(sizeof(struct tmp_chain));

		init_apply_chain(apply_head);//apply_head->mem_size=100
		//initNameAndAge(char *name, int age)
		while(1)
		{
				printf("input apply memory size:");
				scanf("%d", apply_mem_size);
				//判断申请内存大小是否有效
				if(apply_mem_size > apply_head->mem_size)
				{
						printf("memory not enough.\n")
						continue;
				}
				while(apply_mem_size!=0)
				{
						//在申请链表中查找mem_size值最大节点
						apply_max_node=find_from_applyChain_maxMemSizeNode(appley_head);

						if(apply_mem_size == apply_max_node->mem_size)
						{
								//将最大值结点从申请链表中删除
								move_from_applyChain(apply_max_node);
								//删除后插入临时链表
								insert_tail_tmpChain(tmp_head, apply_same_node);

								apply_head->mem_size-=apply_mem_size;
								apply_mem_size=0;
						}
						else
							if(apply_mem_size<apply_max_node->mem_size)
							{
									//查找与申请内存大小相同的结点
									apply_same_node=find_from_applyChain_samMemSizeNode(apply_head, 
																						apply_mem_size);
									//没找到
									if(apply_same_node==NULL)
									{
											//新建一个结点
											pnew=init_node(sizeof(struct apply_chain));
											//根新数据域
											pnew->mem_size=apply_mem_size;
											pnew->mem_index=apply_max_node->mem_index;
											apply_max_node->mem_size-=apply_mem_size;
											
											apply_head->mem_size-=apply_mem_size;
											apply_mem_size=0;
											//插入临时链表
											insert_tail_tmpChain(tmp_head, pnew);
									}
									else//找到相同结点
									{
											move_f：rom_applyChain(apply_same_node);

											insert_tail_tmpChain(tmp_head, apply_same_node);

											apply_head->mem_size-=apply_mem_size;
											apply_mem_size=0;
									}
							}
							else//申请内存大于最大值
							{
									move_from_applyChain(apply_max_node);
									insert_tail_tmpChain(tmp_head, apply_max_node);
									
									apply_mem_size-=apply_max_node->mem_size;

									apply_head->mem_size-=apply_max_node->mem_size;
							}

				}
				//统计临时链表结点个数
				tmpNodeNum=count_tmpChain_nodeNum(tmp_head);
				//开辟记录结点
				precord_new=init_node(sizeof(struct record));
				init_record_node(precord_new);//precord_new->nodeNum=malloc((tmpNodeNum+1)*sizeof(struct node *))
				for(i=0, pindex=tmp_head->next; i<tmpNodeNum; i++, pindex=pindex->next)
				{
					precord_new->nodeNum[i]=pindex;

				}
				precord_new->nodeNum[i]=NULL;
				//插入到记录链表中
				insert_to_recordChain(record_head, precord_new);
				//将临时链表中结点插入到释放链表中
				ptmp_node=move_from_tmpChain_head(tmp_head);
				insert_tail_to_freeChain(free_head, ptmp_node);
		}

}











