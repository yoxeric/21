#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

int main() {

	// printf("is alpha: \n %d %d %d \n", ft_isalpha('A'),ft_isalpha('['),ft_isalpha('3'));
	// printf("is digit: \n %d %d %d \n", ft_isdigit('2'),ft_isdigit('n'),ft_isdigit('+'));
	// printf("is alnum: \n %d %d %d \n", ft_isalnum('y'),ft_isalnum('2'),ft_isalnum('!'));
	// printf("is ascii: \n %d %d \n", ft_isascii('3'),ft_isascii(132));
	// printf("is print: \n %d %d \n", ft_isprint('*'),ft_isprint('\t'));
	// printf("ft_strlen:\n %d %d \n", ft_strlen("bc3. a53@^N"),ft_strlen("^!9\niovh"));
	//
	// char a[8] = "this is";
	// char b[17] = "the fact that is";
	// char c[20] =  "not ";
	// char d[10] = "from here ";
	// char e[30] = "why is it here ";
	// char f[20] = "now and then";
	// char g[9];
	//
	// ft_strlcpy(a,b,8);
	// printf("strlcpy:\n %s. \n",a);
	// ft_strlcpy(g,b,9);
	// printf(" %s. \n",g);
	//
	// ft_strlcat(e, f, 0);
	// printf("strcat:\n %s. \n",e);
	// ft_strlcat(c, d, 0);
	// printf(" %s. \n",c);
	//
	// printf("toupper:\n %c %c   \n", ft_toupper(57),ft_toupper('a'));
	// printf("tolower:\n %c %c   \n", ft_tolower(97),ft_tolower('G'));
	//
	// printf("ft_strchr: \n %s %s \n", ft_strchr("wduibeueibc",'u'),ft_strchr("15dc",'1'));
	// printf("ft_strrchr:\n %s %s \n", ft_strrchr("wduivbeie ",'i'),ft_strrchr("15d!evq!e",'!'));
	// printf("ft_strncmp:\n %d %d \n",ft_strncmp("skie","biliki",5),ft_strncmp("balak","rah skie",5));
	// printf("ft_strnstr:\n %s %s %s \n", strnstr("ihvaevbemmncomaina","coma",20),ft_strnstr("iahvaeincomaavch","coma",20)
	// 	,ft_strnstr("pamari gibala", "ri",7));
	//
	// printf("ft_atoi:   \n %d %d \n", ft_atoi("  -15643313asaf"),ft_atoi(" ++--+15653afano"));

	char str[50] =  "hello call the police there is an invation here ";
	char str2[50] = "9/11 what's your umergency";
	char str3[50] = "ok no problemos";
	char str4[50] = "there is fire in the basement";
	char str5[50] = "yeh there is fire in the basement yeh";

	ft_memset(str,'$',5);
	printf("ft_memset: \n %s.\n", str);
	ft_bzero(&str2[8],3);
	printf("ft_bzero:  \n %s.\n", str2);
	ft_memcpy(str2,str,17);
	printf("ft_memcpy: \n %s.\n", str2);
	ft_memmove(str3,str4,30);
	printf("ft_memmove:\n %s.\n", str3);
	printf("ft_memchr: \n %s.\n", ft_memchr (str,'v',50));
	printf("ft_memcmp: \n %d \n", ft_memcmp (str,str2,30));

	int *t = ft_calloc(3,5);
	int i = 0;
	while(++i < 9) { *(t+i) = i; }
	i = 0;
	printf("ft_calloc: \n");
	while(++i <= 9) { printf(" %d,", *(t+i)); }
	printf("\n");

	printf("ft_strdup:\n %s. \n", ft_strdup(str3));

	printf("ft_substr:\n  %s. \n", ft_substr(str,15,6));
	printf("ft_strjoin:\n %s. \n", ft_strjoin(str,str3));
	ft_memset(&str[43],'$',5);
	printf("ft_strtrim:\n source: %s. \n %s. \n",str, ft_strtrim(str,"$$$"));
	printf(" %s. \n", ft_strtrim(str5,"yeh"));

	char **string;
	//char *st = "bjbbu ausbvaius auci achuaic abc";
	//string = ft_split(st,' ');
	string = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	printf("ft_split: \n");
	int n = -1;
	while(++n < 12)
		printf(" %s,",string[n]);
	printf("\n");

	printf("ft_itoa:\n %s. \n",ft_itoa(-2147483648LL));

	// *ft_strmapi
	// ft_striteri
	// ft_putchar_fd
	// ft_putstr_fd
	// ft_putendl_fd
	// ft_putnbr_fd


	return 0;
}
