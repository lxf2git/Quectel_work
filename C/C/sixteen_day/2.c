#include<stdio.h>
typedef struct Birthday
{
	int year;
	int month;
	int day;

}sBirth,*pBirth;
typedef struct Person
{
	char name[20];
	struct Birthday *pbirth;//sBirthday birthday;
}sPerson,*pPerson;
int main()
{

	//sPerson person1;
	//printf("name:%s birth:%d %d %d\n",person1.name,
		//			person1.birthday);
		//
	pPerson person1=(pPerson)malloc(sizeof(sPerson));
	person1->pbirth = (pBirth)malloc(sizeof(sBirth));
	scanf("%d",&person1->pbirth->year);
	printf("year:%d\n",person1->pbirth->year);
	printf("size:%d\n",sizeof(sPerson));
}


