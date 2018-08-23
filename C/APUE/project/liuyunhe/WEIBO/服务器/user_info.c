#include"apue.h"
/*查看个人信息*/
int user_info(struct message sMe,pUser pHead)
{
	printf("进入个人信息\n");

	char buf[1024];
	pUser ptmp = pHead->next;
	while(strcmp(ptmp->id,sMe.userid)!=0)
	{
		ptmp=ptmp->next;
	}
	printf("id%s\n",ptmp->id);
	strcpy(buf,"id  ");
	strcat(buf,ptmp->id);
	strcat(buf,"\n");
	strcat(buf,"name  ");
	strcat(buf,ptmp->name);
	strcat(buf,"\n");
	printf("buf:%s",buf);

	int num=0;
	int n=0,m=1,t=10;
	char a[1024]={"\0"};
	pAttenrion pat = ptmp->attenrion_Head;   //attenrion  number
	while(pat->next!=ptmp->attenrion_Head)
	{
		num++;
		pat = pat->next;
	}
	strcat(buf,"atten  ");
	
	while(m!=0)
	{
		m = num/t;
		n++;
		t = t*10;
	}
	while(num!=0)
	{
			m = num%10;
			m=m+48;
			a[n-1] = (char)m;
			num = num/10;
			n--;
	}
	strcat(buf,a);
	strcat(buf,"\n");
	
	num = 0;n = 0;m = 1;t = 10;
	bzero(a,sizeof(a));        //fans   number
	pFans pFfans = ptmp->fans_Head;
	while(pFfans->next!=ptmp->fans_Head)
	{
		num++;
		pFfans = pFfans->next;
	}
	while(m!=0)
	{
		m = num/t;
		n++;
		t = t*10;
	}
	while(num!=0)
	{
			m = num%10;
			m=m+48;
			a[n-1] = (char)m;
			num = num/10;
			n--;
	}
	strcat(buf,"fans  ");
	strcat(buf,a);
	strcat(buf,"\n");
	printf("buf1:%s",buf);
	write(sMe.sockfd,buf,strlen(buf));

	return 0;
}
