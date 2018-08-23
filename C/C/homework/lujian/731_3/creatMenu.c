 #include"main.h"
int   creatMenu(int j)
{
	int k = 0;
	struct Account
	{
		char name[7];
		char passwd[7];
		char newpasswd[7];
		long newid;
		double  banlance;
		int i;
		char ch;	
	} _info[100];
		if (j >= 100)
		{
				exit(0);
		}
	srand(time(NULL));
	_info[j].i = 0;
	_info[j].newid = rand();
	printf("please input passwd\n");
	do
	{
			scanf("%s",_info[j].passwd);
			_info[j].i++;
	
	}while((strcmp(_info[j].passwd,"545314") != 0)
					&& (_info[j].i < 3)
				  	&& printf("passwd error pleasinput again\n"));
		if(_info[j].i >= 3)
		{
			printf("you have input 3 time error passwd!\n ");
			return 0;
		}
		else 
		{
	    printf("please input account name:\n");
		scanf("%s",&_info[j].name);
		printf("please input you account new passwd!\n");
		scanf("%s",&_info[j].newpasswd);
		sleep(1);
		printf(" banlance:￥00000.00000\n");
		sleep(1);
		printf(" gain new account id %ld\n",_info[j].newid);
		sleep(1);
		printf("compelet creatMenu !\n");
		printf("please back \n");
		getchar();
		_info[j].ch = getchar();
		}
	
		for (k = 0; k <=j ; k++ )
 
		{
			printf("the%d name =%s \n",k, _info[k].name);
			printf("the%d passwd=%s \n",k, _info[k].passwd);
			printf("the%d newpasswd =%s \n",k, _info[k].newpasswd);
			printf("the%d newld =%ld \n",k, _info[k].newid);
			printf("the%d balance=%lf \n",k, _info[k].banlance);
        	printf("\n");
		}


		
		return 0;

}
