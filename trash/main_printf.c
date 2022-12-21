#include <stdio.h>

int main()
{
	char c = 'E';
	char *s = "it is time";
	int i = 811;
	int d = 32;
	unsigned int u = 26;
	//int max = -2147483648;
	void *p = &s;
	int x = 314;
	unsigned int xx = 158;

	int res;

	res = ft_printf("hello %% %c %s %i %d %u %x %X %p\n",c,s,i,d,u,x,xx,p);
	printf("%d \n",res);
	res = printf("hello %% %c %s %i %d %u %x %X %p\n",c,s,i,d,u,x,xx,p);
	printf("%d \n",res);
}
