#include "apue.h"
Thread_Data * send_friendCircle_look(int mode,char* destAddr,char* dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		pTemp->data.mode = FRIENDCIRCLE_LOOK;
		return pTemp;
}
