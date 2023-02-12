#include<stdio.h>
#include<stdlib.h>
int	main()
{
	char ch1[30] = "hello samir";
	char ch2[30] = "how are you a 3chiri";
	char chr[20];
	int n;
	int x;
	int y;

	n = 0;
	x = 6;
	while(n < x)
	{
		chr[n] = ch1[n];
		n++;
	}
	y = 17;
	while(n < y)
	{
		chr[n] = ch2[n - x];
		n++;
	}
	chr[n++] = '\n';
	chr[n] = '\0';
	printf("%s",chr);
	return(0);
}
