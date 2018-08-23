#include<stdio.h>
int main()
{
	int i;
	char ch[5],num;
	//scanf("%d",&num);
	for(i=0;i<5;i++){
			scanf("%c",&num);
			getchar();
			//if(num>=48&&num<=57||num==45)
			if(num>=0&&num<=9)
			num=num+48;
					ch[i]=num;
	}
			puts(ch);
			return 0;
}
