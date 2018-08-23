#include"main.h"
int  saveMenu()
{
		char choose_ch;
		printf("******pleae choose menu***:\n");
		printf("1:craetMenu\n 2:withdrawMenu\n3:queryMenu\n4:back your card\n");
		scanf("%c",&choose_ch);
		
				switch (choose_ch)
				{
						case '1':
								{
								printf("weclome to creatMenu()\n");
								static int j = 0;
								creatMenu(j);
								j++;
								}
								break;
						case '2':
								printf("weclome to withdrawMenu()\n");
								withdrawMenu();
								break;
						case '3':
								printf("weclome to queryMenu()\n");
								queryMenu(); 
								break;
						default:
								printf("please back your card!\n"); 
								break;		

				}
	
		return 0;

}
