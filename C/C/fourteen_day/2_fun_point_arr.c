#include<stdio.h>
#include<string.h>

void str_fun(char *(*p[2])(char *,const char*),char *s1,char *s2)
{

		int choose;
		char *pret;
		do
		{
			printf("please input your choose:\n");
			scanf("%d",&choose);	
			if(choose!=1&&choose!=2)
			{
				continue;
			}
				pret = (*p[choose-1])(s1,s2);
				printf("result:%s\n",pret);

		}while(choose!=3);
}
int main()
{
	char *(*pf[2])(char *,const char*)={strcat,strcpy};	
	char str1[100]="abcdefghijk";
	char str2[50] = "ABCDEFGHIJK";
	str_fun(pf,str1,str2);
	return 0;

}
