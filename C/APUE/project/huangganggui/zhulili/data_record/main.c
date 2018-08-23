#include"main.h"


int main()
{
	pDis pHead_D = NULL;
	pNode pHead_N = NULL;
	pNode ptmp = NULL;
	int i,num,n;	
	init_node(&pHead_D,sizeof(sDis));	
	init_node_node(&pHead_N,sizeof(sNode));
	printf("比较数字的个数");
	scanf("%d",&n);
	create_single_chain(pHead_D);
	create_double_chain(pHead_N,n);			
	num = judge_num(pHead_N,n);
	for(i=1;i<=num;i++)
	{
		distribute(pHead_N,pHead_D,i,num);
		collected(pHead_N,pHead_D);		
	}
	printf("排序的结果:\n");
	for(ptmp=pHead_N->next;ptmp!=pHead_N;ptmp=ptmp->next)
		printf("%d  ",ptmp->data);
	printf("\n");
	return 0;
}
