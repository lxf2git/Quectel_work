#include"ftp.h"
int recevie_course(int type, struct recv_to_deal *data, int msg_id)
{
		Msg m;
		int ret;
		ret = msgrcv(msg_id, &m, sizeof(m)-sizeof(m.type), type, 0);
		if(ret < 0)
		{
				perror("msgrcv");
				ret = msgrcv(msg_id, &m, sizeof(m)-sizeof(m.type), type, 0);
				if(ret< 0)
				{
						perror("msgrcv!!!");
						return FAIL;
				}
		}
		*data = m.data;
		return SUC;
}


