#include"ftp.h"
int recevie_course(int type, struct recv_to_deal *data, int *msg_id)
{
		Msg m;
		char port[10];
		int ret;
		*msg_id = msgget(0x6666, O_RDWR);
		ret = msgrcv(*msg_id, &m, sizeof(m)-sizeof(m.type), type, 0);
		if(ret < 0)
		{
				perror("msgrcv");
				return FAIL;
		}
		*data = m.data;
		return SUC;
}
