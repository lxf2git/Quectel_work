#include<stdio.h>
/*共用体（联合）union
	允许不同类型的成员占用同一段内存
	在某一时刻 只处理共用体中的某个成员
*/

typedef union un_name
{
	int _a;
	float f;
	char _b;
}sUn,*pUn;
int main()
{
	sUn a;
//	printf("%d",sizeof(a));	
	
	a._a = 99;
	printf("a._a %d\n",a._a);
	printf("a._b %c\n",a._b);

	a._b = 'd';
	printf("a._b %c\n",a._b);
	printf("a._a %d\n",a._a);

	printf("&a._b %p\n",&a._b);
	printf("&a._a %p\n",&a._a);

	a.f = 3.0;
	printf("a.f %f\n",a.f);

	return 0;

}
