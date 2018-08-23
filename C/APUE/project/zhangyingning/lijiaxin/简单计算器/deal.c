#include"stack.h"

void deal(pStack p_data,pStack p_oper)
{
		switch(pop(p_oper))
		{
				case 1:push(p_data,pop(p_data) + pop(p_data));break;
				case 2:push(p_data,mul(p_data));break;
				case 3:push(p_data,pop(p_data) * pop(p_data));break;
				case 4:push(p_data,del(p_data));break;
		}
}
