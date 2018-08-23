
#include<stdio.h>
int main()
{
	int blank=0,num=0,other=0,ch=0;
	char nu;
	printf("请输入一个字符串\n");
	for(;;)
	{
		while((nu=getchar())!=10)
		{
		if(nu>='A'&&nu<='Z'||nu>='a'&&nu<='z')
				ch++;
		else if(nu==' ')
				blank++;
		else if(nu>='0'&&nu<='9')
				num++;
		else
			other++;
		}
	

	printf("空格%d个，数字%d个，字母%d个，其他%d个。",blank,num,ch,other);
	break;
	}
}
