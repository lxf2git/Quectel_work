
int insert_chain(Thread_Data pHead, Thread_Data pnew)
{
		pHead->prev->next = pnew;
		pnew->prev = pHead->prev;
		pHead->prev = pnew;
		pnew->next = pHead;
}



Thread_Data * send_to_service(int mode, char *destAddr, char *dest_user)
{
		my_jmpMenu(2);
		int fd, ret;
		Thread_Data *pHead;
		chain_init(&pHead);
		scanf("%s",	pHead->data.fileName);
		fd = open(pHead->data.fileName, O_RDWR)
		if(fd < 0)
		{
				perror("open");
				return -1;
		}
		while(1)
		{
				Thread_Data *pnew = NULL;
				chain_init(&pnew);
				bzero(&(pnew->data.dorinform.data), sizeof(pnew->data.dorinform.data));
				ret = read(fd, pnew->data.dorinform.data, sizeof(pnew->data.dorinform.data));
				insert_chain(pHead, pnew);

				if(ret < 0)
				{
						pnew->data.mode = REQUES_EXIT;
						return -1;
				}

		}

		return pHead;



}
