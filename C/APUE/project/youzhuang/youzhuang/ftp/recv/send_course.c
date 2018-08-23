#include"ftp.h"
int send_course(int type, struct recv_to_deal data, int msg_id)
{
		char port[10];
		int ret;
		Msg m;
		m.type = type;
		m.data = data;
		ret = msgsnd(msg_id, &m, sizeof(m)-sizeof(m.type), 0);
		if(ret < 0)
		{
				perror("msgsnd");
				return FAIL;
		}
		return SUC;
}
