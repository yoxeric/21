#include<stdio.h>

int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char *str;
//	int x;
//	unsigned int y;
	char a[20] = "this ";
	char b[9] = "is very ";
    char c[20] =  "not ";
    char d[10] = "from here ";
    char e[5] = "now ";
    char f[16] ="why is it here ";

	printf("%d \n",ft_strcmp("sobba d","koppa"));
    printf("%d \n",ft_strcmp("zid","7yed"));

    printf("%d \n",ft_strncmp("skie","biliki",5));
    printf("%d \n",ft_strncmp("balak","rah skie",5));
	
	ft_strcat(a, b);
    printf("%s \n",a);

	ft_strncat(c, d, 4);
	printf("%s \n",c);

	str = "pamari gibala";
	printf("%s \n",ft_strstr(str, "ri"));

	ft_strlcat(f, e, 18);
    printf("%s \n",f);

}
