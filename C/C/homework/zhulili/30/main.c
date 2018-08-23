#include"main.h"

int main()
{
	int i,t,ma;
	char a[500]={0};
	char string1[500]={0},string2[200]={0};
	printf("请输入两个4个以内的字符串string1[i]和string2[i]：\n");
	reorder(&string1[0]);
	getchar();
	reorder(&string2[0]);
	getchar();
	strcat(string1,string2);
	printf("合并后的字符串为：%s\n",string1);
	reorder1(string1);
	delete(string1);
	return 0;
}
