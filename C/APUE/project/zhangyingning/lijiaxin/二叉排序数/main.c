#include"tree_sort.h"
enum ss
{
		creat=1,
		delete,
		print,
		exit_
};
int main()
{
		pTree pHead=NULL;
		init_tree(&pHead);
		p = &pHead;
		do
		{
				int i;
				printf("请选择:\n  1:创建一个二叉树\n  2:删除二叉数的枝叶\n  3:打印结果\n  4:退出\n");
				scanf("%d",&i);
				switch(i)
				{
						case creat:creat_(pHead);break;
						case delete:delete_(pHead);break;
						case print:print_(pHead);break;
						case exit_:exit(0);break;
						default:printf("您的输入有误,请重新输入\n");break;
				}
		}
		while(1);

}
