//一个球从100米高度落下，一次弹跳落下高度的一半，第十次弹跳走过多少路程

#include<stdio.h>
int main()
{
	float chang = 0, h1 = 0, h;
	int ci, ci1;
	printf("请输入高度和弹跳次数，每次输入以空格间隔\n");
	scanf("%f %d",&h,&ci1);
	printf("再%.2f高度下弹跳%d次\n",h,ci1);
	for (ci = 1;ci <= ci1;++ci)
	{
		h1 = h + h / 2;
		h = h / 2;
		chang += h1;
	}
	printf("共经过米%.2f此时高%.2f\n",chang,h);
	return 0;
}
