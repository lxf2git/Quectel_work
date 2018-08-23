#include<stdio.h>
#include<stdlib.h>

void  calculate();
void area(float r);
void girth(float r);

int main()
{
	calculate();//input  switch  		
	printf("i am main\n");
	return 0;
}

void  calculate()
{
	float r;
	char m;

	do
	{
		printf("please input m r:\n");
		scanf("%c",&m);	
		getchar();
		if(m!='d')
		{
			scanf("%f",&r);
		}
		switch(m)
		{
			case 'a':
					area(r);
					break;
			case 'b':
					girth(r);
					break;
			case 'c':
					area(r);
					girth(r);
					break;
			case 'd':

					exit(0);//
					//return 0;//返回主调函数	
		}
	}while(m!='d'&&getchar());

}

void area(float r)
{
	printf("%f\n",3.14*r*r);
}

void girth(float r)
{
	printf("%f\n",2*3.14*r);
}
