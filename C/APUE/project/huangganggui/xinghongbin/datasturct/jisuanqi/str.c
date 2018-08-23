#include"str.h"
void sort_char(char **argv,int *p,pSig pHead)                                  //分检命令行参数
{
		int offset;
		int length;
		int result;
		int number=0;
		length = strlen(argv[1]);
		for(offset=0 ; offset < length ; offset++)
		{
				result = num_or_sign(argv,offset);
				if(result != 1)
				{
						deal_figure(argv,offset,number,p);
						number++;
						if(result == 2)
						deal_sign(argv,offset,number-1,pHead,p);
				}


		}
		int j;
	for(j=0;j<number;j++)
	{
			printf("number %d\n",p[j]);
	}
}
void deal_figure(char **argv,int i,int number,int *p)                         //字符数字化
{
		int bit;
		int bf=0;
		for(bit=0,i-=1; (num_or_sign(argv,i) == 1) && (i>=0);i--,bit++)
		{
				bf += (argv[1][i]-48) * (ten_power(bit));
		}
		p[number]=bf;

}
int num_or_sign(char **argv,int i)								//字符范围确定				
{
		if( (argv[1][i]>=48) && (argv[1][i]<=57))
				return 1;
		if( ((argv[1][i]>=40) && (argv[1][i]<=47) && (argv[1][i] != 44) && (argv[1][i] != 46)) || (argv[1][i] == 37)|| (argv[1][i] == 91)|| (argv[1][i] == 93))
				return 2;
//		if((argv[1][i]== 40)|| (argv[1][i]== 41))
//				return 3;
		return 4;
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
void chain_init(pSig *p)
{
		create_memory((void**)p,sizeof(sSig));
		(*p)->next = (*p);
		(*p)->prev = (*p);
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
				case '(':
						return 1;
				case ')':
						return 2;		

						
		}
}
void deal_sign(char **argv,int i,int number,pSig pHead,int *arr)
{		
		pSig p;
		chain_init(&p);
		pSig pTemp=pHead->prev;
//		printf("%d\n",sign_priority(argv[1][i]));
		p->sign = argv[1][i];
		p->number = number;
		printf("pnumber%d psign %c\n",p->number,p->sign);

		p->next = pTemp->next;
		p->prev = pTemp;
		pTemp->next->prev = p;
		pTemp->next = p;
}
