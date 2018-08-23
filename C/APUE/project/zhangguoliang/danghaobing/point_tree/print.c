#include"print.h"
void print(pTree pStart)
{
		if (pStart->tr_lc != NULL)
		{
			print(pStart->tr_lc);
		}
		printf("%d ",pStart->tr_data);
		if (pStart->tr_rc != NULL)
		{
				print(pStart->tr_rc);
		}
}
