#include"shed.h"
void menu(pShe p,int data);
void convert_bin(pShe p,int data);
void convert_oct(pShe p,int data);
void convert_hex(pShe p,int data);
int main()
{
		sShe shed;
		int data;
		printf("input data\n");
		scanf("%d",&data);
		menu(&shed,data);
		


}
void menu(pShe p,int data)
{
		void (*pfun)(pShe,int);
		int choose;
		int ret;
		do
		{
				printf("input choose  (input type ofchar exit)\n");
				printf("1 bin\n");
				printf("2 oct\n");
				printf("3 hex\n");
				ret = scanf("%d",&choose);
				if(ret != 0)
				{
						switch(choose)
						{
								case 1:
										shed_init(p);
										pfun = convert_bin;
										break;
								case 2:
										shed_init(p);
										pfun = convert_oct;
										break;
								case 3:
										shed_init(p);
										pfun = convert_hex;
										break;
								default:
										printf("input error\n");
										return;		

						}
						pfun(p,data);

				}
		}while(ret != 0);

}
void convert_bin(pShe p,int data)
{
		int result;
		while(data != 0)
		{
				push(p,data%2);
				data/=2;
		}
		printf("\nresule: ");
		while(pop(p,&result) != EMPTY)
		{
				printf(" %d",result);
		}
		return ;

}
void convert_oct(pShe p,int data)
{
		int result;
		
		while(data != 0)
		{
				push(p,data%8);
				data/=8;
		}
		printf("\nresule: ");
		while(pop(p,&result) != EMPTY)
		{
				printf(" %d",result);
		}
		return ;
}
void convert_hex(pShe p,int data)
{
		int result;
		
		while(data != 0)
		{
				push(p,data%16);
				data/=16;
		}
		printf("\nresule: ");
		while(pop(p,&result) != EMPTY)
		{
				if(result >=10)
				{
						result = 65+(result-10);
				}
				else
				{
						result +=48; 
				}
				printf(" %c",result);
		}
		return ;
}
