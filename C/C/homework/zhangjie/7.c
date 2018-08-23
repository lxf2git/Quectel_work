#include<stdio.h>
int main()
{
	char ch;
	int y,k,s,q;
	k=0;y=0;s=0;q=0;
	//ch=getchar();//接取键入的字符；
	while(ch!=10)
	{
		scanf("%c",&ch);
		if(ch==32)
		k++;
		else if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
		y++;
		else if(ch>=48&&ch<=57)
		s++;
		else if(ch!=10) 
		q++;
		//ch=getchar();;			
	}
		printf("空格数为%d\n",k);
		printf("英文字母数为%d\n",y);
		printf("数字数为%d\n",s);
		printf("其他字符数为%d\n",q);
	return 0;
}
