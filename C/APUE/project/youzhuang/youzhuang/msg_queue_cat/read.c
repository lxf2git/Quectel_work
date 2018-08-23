#include"main.h"

int main()
{
		Msg m;
		key_t key = ftok("/root", 'a');
		int id = msgget(key, O_RDWR);
		msgrcv(id, &m, sizeof(m)-sizeof(m.type), 666, 0);
		m.type=777;
		int fid = open(m.msg, O_RDONLY);
		memset(m.msg,0,sizeof(m.msg));
		int len = read(fid, m.msg, sizeof(m.msg)-1);
		while(len>0)
		{
				msgsnd(id, &m, sizeof(m)-sizeof(m.type),0);
				memset(m.msg,0,sizeof(m.msg));
				len = read(fid, m.msg, sizeof(m.msg)-1);
		}
		msgsnd(id, &m, sizeof(m)-sizeof(m.type),0);
		return 0;
}
