#include"main.h"

void data_in(pStack_in ORND,char *str)
{
		int i;
		int EXIT=0;
		int data=0;
		sStack_ch ORNP;
		init_OP(&ORNP);

		for(i=0;i<strlen(str);i++)
		{
				for(;*(str+i)<58&&*(str+i)>47;i++)
				{
						data=data*10+(*(str+i)-48);
						EXIT++;
				}
				if(EXIT!=0)
				{
					push_in(ORND,data);
					data=0;
					EXIT=0;
				}

				char_select(ORND,&ORNP,*(str+i));
		}	
		print(ORND,&ORNP);
		free(ORNP.bottom);
}
int main()
{
		char *str;
		great_memory(&str,50*sizeof(char));

		sStack_in ORND;
		init_OD(&ORND);

		printf("输入要运算的表达式\n");
			scanf("%s",str);
			data_in(&ORND,str);
		free(ORND.data_head);
		free(str);
}
