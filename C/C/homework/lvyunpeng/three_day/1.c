#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
float s(float r);
float l(float r);

int main()
{
	char a;
	float r;
		for(;;)
		{
			printf("请输入半径：");
			scanf("%f",&r);
			printf("请输入字符：\n");
			scanf("%c",&a);
			int m=getchar();
			if(m=='a')
			{
				float b = s(r);
				printf("面积:%f\n",b);

			}
			if(m=='b')
			{
				float c = l(r);
				printf("周长:%f\n",c);

			}

			if(m=='c')
			{
				float b = s(r);
				float c = l(r);
				printf("面积:%f\n 周长:%f\n",b,c);

			}
			if(m=='d')
			{
				return 0;

			}
			if(m!='a'||m!='b'||m!='c'||m!='d')
			{
				printf("请重新输入：\n");
			}

		}		
	return 0;
}
float s(float r)

{
	return 3.14*r*r;
}

float l(float r)
{
	return (2*3.14*r);
}
	
