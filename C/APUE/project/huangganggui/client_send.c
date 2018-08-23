#include "apue.h"
Thread_Data * send_friendCircle_send(int mode,char* destAddr,char* dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		puts("请输入");
		scanf("%s",pTemp.data.dorinform.data);
		pTemp->data.mode = FRIENDCIRCLE_SEND;
		return pTemp;
}
