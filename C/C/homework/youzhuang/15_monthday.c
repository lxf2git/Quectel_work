
int bissextile(int year);

int monthday(int year,int month,int day)
{
		int run;
		run=bissextile(year);
		if(month==2&&run==1)
		{
				return 28;
		}
		if(month==2&&run==0)
		{
				return 29;
		}
		if(month==4||month==6||month==9||month==11)
		{
				return 30;
		}
		else
		{
				return 31;
		}
}
