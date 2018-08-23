#include"main.h"

int main()
{
	pStu pHead=NULL;
	init_node(&pHead,sizeof(Stu));
	int a,i,m;
	while(1)
	{
		printf("========================\n按1输入学生信息\n按2输入查找年龄\n按3保存学生信息\n按4按ID清除学生信息\n按5显示所有学生信息\n按6退出程序\n===================\n");
	scanf("%d",&a);
	switch(a)
		{
			case 1:
					Insert_chain(pHead);
						break;
			case 2:
					printf("输入要查找的年龄：");
					scanf("%d",&i);
					show_age(i);
						break;
			case 3:
					write_chain(pHead);
						break;
			case 4:
					printf("输入要删除的ID号：");
					scanf("%d",&m);
					del_chain(pHead,m);

			case 5:
					show_all(pHead);


			case 6:
					break;

		}
			if(a==6)
				break;
	}
 	return 0;
}
