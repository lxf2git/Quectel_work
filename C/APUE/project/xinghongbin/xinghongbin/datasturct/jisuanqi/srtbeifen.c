#include"str.h"
void sort_char(char **argv)                                   //分检命令行参数
{
		pSig pHead;
		chain_init(&pHead);
		int offset;
		int length;
		int result;
		int number=0;
		int *p;
		create_memory((void**)&p,strlen(argv[1]));
		length = strlen(argv[1]);
		for(offset=0 ; offset < length ; offset++)
		{
				result = num_or_sign(argv,offset);
				if(result != 1)
				{
						deal_figure(argv,offset,number,p);
						number++;
				}
				if(result == 2)
				{
						deal_sign(argv,offset,number,pHead);
				}


		}
		int j;
	for(j=0;j<number;j++)
	{
			printf("you%d\n",p[j]);
	}
//		printf("%d\n",p[1]);
//		output(pHead,p,number);
}
void deal_figure(char **argv,int i,int number,int *p)                         //字符数字化
{
		int bit;
		int bf=0;
//		for(bit=0,i+=1; num_or_sign(argv,i) == 1;i++,bit++)
//		{
//				af = (argv[1][i]-48) * (ten_power(bit));
//				
//		}
		for(bit=0,i-=1; (num_or_sign(argv,i) == 1) && (i>=0);i--,bit++)
		{
				bf += (argv[1][i]-48) * (ten_power(bit));
//				printf("%c %d\n",argv[1][i],ten_power(bit));
		}
		p[number]=bf;
//		p[number] = af;
//		printf("%d \n",bf);

}
int num_or_sign(char **argv,int i)								//字符范围确定				
{
		if( (argv[1][i]>=48) && (argv[1][i]<=57))
				return 1;
		if( ((argv[1][i]>=42) && (argv[1][i]<=47) && (argv[1][i] != 44) && (argv[1][i] != 46)) || (argv[1][i] == 37))
				return 2;
		return 3;
}
int ten_power(int i)                                           // 10的次方
{
		int ten = 1;
		for(;i>0;i--)
				ten *=10;
		return ten;
				
}
void create_memory(void ** p,int size)
{
		*p = malloc(size);
		if(NULL == *p)
		{
				printf("memory error\n");
				exit(-1);
		}
}
void deal_sign(char **argv,int i,int number,pSig pHead)
{		
		pSig p;
		chain_init(&p);
		printf("%d\n",sign_priority(argv[1][i]));
		p->sign = argv[1][i];
		p->number = number;
		pSig pTemp=pHead;
		while(pTemp->next != pHead)
		{
				if( (sign_priority(pTemp->next->sign)) > (sign_priority(p->sign)))
				{
						p->next = pTemp->next;
						p->prev = pTemp;
						pTemp->next->prev = p;
						pTemp->next = p;

						return;	
				}
				pTemp = pTemp->next;

		}
		p->next = pTemp->next;
		p->prev = pTemp;
		pTemp->next = p;
		pTemp->next = p;
}
int sign_priority(char sign)
{
		switch(sign)
		{
				case '*':
						return 3;
				case '/':
						return 3;
				case '+':
						return 4;
				case '-':
						return 4;
				case '%':
						return 3;
			//	case ';':
			//			return ;		

						
		}
}
void chain_init(pSig *p)
{
		create_memory((void**)p,sizeof(sSig));
		(*p)->next = (*p);
		(*p)->prev = (*p);
}
/*
void output(pSig pHead,int *p,int len)
{
	int sum = p[pHead->next->number];
	pSig pTemp = pHead->next;
		int i=0;
		int s=0;
	while(pTemp != pHead)
	{
		if(pTemp->number > pTemp->prev->number)
				i = s;
		i = s+1;
		printf("%d %c %d %d  %d\n",p[pTemp->number-1-i],pTemp->sign,p[pTemp->number-i],pTemp->number-i ,i);
		switch(pTemp->sign)
		{
			case '*':
				p[pTemp->number-1-i] = ((p[pTemp->number-1-i]) * (p[pTemp->number-i]));
				p[pTemp->number-i] = p[pTemp->number-1-i];
				break;
			case '/':
				p[pTemp->number-1-i] = ((p[pTemp->number-1-i]) / (p[pTemp->number-i]));
				p[pTemp->number-i] = p[pTemp->number-1-i];
				break;
			case '+':
				p[pTemp->number-1-i] =((p[pTemp->number-1-i]) + (p[pTemp->number-i]));
				p[pTemp->number-i] = p[pTemp->number-1-i];
				break;
			case '-':
				p[pTemp->number-1-i] = ((p[pTemp->number-1-i]) - (p[pTemp->number-i]));
				p[pTemp->number-i] = p[pTemp->number-1-i];
				break;
			case '%':
				p[pTemp->number-1-i] = ((p[pTemp->number-1-i]) % (p[pTemp->number-i]));
				p[pTemp->number-i] = p[pTemp->number-1-i];
				break;
		}
		del_arr(pTemp->number-i,p,len);
		len--;
		s++;                                      //youde  dong le you de meidong

		printf("%d\n",p[pTemp->number-s]);
		pTemp = pTemp->next;
	}
}
void del_arr(int i,int *p,int len)
{
	for(;i<len;i++)
	p[i] = p[i+1];
		int j;
	for(j=0;j<len-1;j++)
	{
			printf("shengyu%d\n",p[j]);
	}
}
*/
