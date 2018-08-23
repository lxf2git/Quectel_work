 #include"main.h"
int withdrawMenu()
{
	char passwd[7];
	int i = 0;
	char choose_ch;
	printf("pleae passwd \n");
	do
	{
	scanf("%s",passwd);
	i++;

	}while ((strcmp(passwd,"545314") != 0 )
					&& (i < 3)
					&& printf("passwd error please again\n"));
	
	if (i >= 3)
	{
          printf("you have input 3 time error passwd! ");
	      return 0;
	}
		while(1)
		{
			printf("please choose\n 1:withdraw\n  2:query\n 3:save\n4:back\n");
			getchar();
			scanf("%c",&choose_ch);
	 if(choose_ch == '1')
				withdraw();
	else if(choose_ch == '2')
				query();
	else if(choose_ch == '3')
				save();
	 else 
			 break;
		}
}
