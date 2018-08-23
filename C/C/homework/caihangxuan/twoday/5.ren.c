#include<stdio.h>
int main()
{
	int yi,er,wu,i=0;
		for(yi=0;yi<=100;yi++)	
			for(er=0;er<=50;er++)
				for(wu=0;wu<=20;wu++)
					if(yi+er*2+wu*5==100)
						i++;
	printf("共有%d种方法\n",i);
}
