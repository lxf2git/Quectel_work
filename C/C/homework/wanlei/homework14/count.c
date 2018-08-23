

int count(int x)
{
	int i;
	int j=1;
	for(i=10;x/i!=0;x/=10)
			j++;
	return j;
}

