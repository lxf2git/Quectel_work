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
	struct Birthday birthday;//sBirthday birthday;
}sPerson,*pPerson;
int main()
{
#if 1		
	sPerson person1={"lantianhua",{1993,6,3}};
	printf("name:%s birth:%d %d %d\n",person1.name,
					person1.birthday.year,person1.birthday.month,person1.birthday.day);	
#endif

}
