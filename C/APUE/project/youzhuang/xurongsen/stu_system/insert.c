#include"main_st.h"
#include"insert.h"
/****
 *
int find_id(pStu phead, pStu pinsert)
pStu posite_in(pStu phead, pStu pin)
int insert(pStu phead, pStu pin, 
				int(*pidfind)(pStu phead,pStu pin),
				pStu(*pinposite)(pStu phead,pStu pin))
 *
 *
 *
 * ****************/
//函数声明
/*
				int(*pidfind)(pStu phead,pStu pin);
				pStu(*pinposite)(pStu phead,pStu pin);
*/
int find_id(pStu phead, pStu pinsert)
{
	pStu p=NULL;
	p=phead;
	while(p != NULL)
	{
		if(p->num == pinsert->num)
		{
			return FAILED;
		}
		p = p->next;
	}
	return SUC;
}

pStu posite_in(pStu phead, pStu pin)
{
	pStu p=NULL,pnew=NULL;
	init_node(&p,sizeof(sStu));
	pnew=phead;
	while(pnew->num < pin->num)
	{
//		printf("pnew:%d  pin:%d\n",pnew->num,pin->num);
		p=pnew;
		pnew=pnew->next;
		if(NULL == pnew)
		{
			break;
		}
	}

	return p;
}

int insert_back(pStu pos,pStu pin)
{
	if(NULL == pos && NULL==pin)
	{
		printf("排序的位置或插入的数不能为空！\n");
		return FAILED;
	}
	pin->next = pos->next;
	pos->next = pin;
	return SUC;
}

int insert(pStu phead, pStu pin, 
				int(*pidfind)(pStu ,pStu ),
				pStu(*pinposite)(pStu ,pStu ))
{
	pidfind = find_id;
	pinposite = posite_in;
	int single=1;//判断id是否重复
	int sert=1;//判断是否插入成功
	pStu pos;//在该节点之后加入节点
	single = (*pidfind)(phead,pin);
	if(single == SUC)
	{
		pos = (*pinposite)(phead,pin);
		sert = insert_back(pos, pin);
		if(sert == SUC)
		{
			printf("insert success!\n");
			printf("insert is pin:id%d  age:%d \n",pin->num,pin->age);
		}
		else
		{
			printf("insert error!\n");
		}
	}
	else if(single == FAILED)
	{
		printf("输入的id有重复！\n");
	}
}

void stu_in(struct Student * pin)
{
	printf("please input id age:");
	scanf("%d%d",&pin->num,&pin->age);
}

pStu pfun_in()
{
	pStu pin;
	init_node(&pin,sizeof(sStu));
	pin->stu_print = stu_in;
	(*pin->stu_print)(pin);
	return pin;
}
