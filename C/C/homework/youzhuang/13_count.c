int count(long x)
{
		int i;
		int m=0;
		for(i=1 ;i<=x;i=i*10)
		{
				m++;
				if(x/i==0)
				{
						break;
				}
		}
		return m;
}
