#include"que_resd.h"

int main()
{
	Txt t,r;
	int ret;
	int id = msgget(0x6666,O_RDWR);

	t.type = 6666;
	strcpy(t.text , "192.168.1.27");
	msgsnd(id,&t,sizeof(t)-sizeof(t.type),0);

	ret = msgrcv(id,&r,sizeof(r)-sizeof(r.type),6667,0);
	if(ret != -1)
	{
			printf("回复：%s\n",r.text);

	}

	return 0;
}

