#include<stdio.h>

char *ft_strcpy(char *dest, char *src);
char *ft_strncpy(char *dest, char *src, unsigned int n);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);
char *ft_strupcase(char *str);
char *ft_strlowcase(char *str);
char *ft_strcapitalize(char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);
void *ft_print_memory(void *addr, unsigned int size);

int main()
{
	int i;
	char str[32] = "goodbye world";
	char str1[18] = "its ok to be ok";
	//char str2[22] = "joe is better than you";
	//char str3[18] = "1342";
	char str4[20] = "THis is nOT Funkable";
	char str5[20];
    char str6[20];
    char str7[20];
	//char str10[25]= "iµ√çΩ†ƒ∑¨∂ˆ∫ç∑µçø∆çøπ˙ƒ";


	i = 0;
	ft_strcpy(str5,str);
	printf("%s \n",str5);
	
	ft_strncpy(str6,str1,13);
    printf("%s \n",str6);

	i = ft_str_is_alpha("aibcacAFAFA");
    printf("alpha \n%d \n",i);
    i = ft_str_is_alpha("ud1ho1j38401");
    printf("%d \n",i);

    i = ft_str_is_numeric("aib14AFAFA");
    printf("num \n%d \n",i);
    i = ft_str_is_numeric("138401");
    printf("%d \n",i);

    i = ft_str_is_lowercase("abfiac");
    printf("lower \n%d \n",i);
    i = ft_str_is_lowercase("aAFCCwbixA");
    printf("%d \n",i);

    i = ft_str_is_uppercase("ACACEA");
    printf("upper \n%d \n",i);
    i = ft_str_is_uppercase("adGmwd");
    printf("%d \n",i);

    i = ft_str_is_printable("unprintable");
    printf("prtable \n%d \n",i);
    i = ft_str_is_printable(" \t bcaui124 \n ");
    printf("%d \n",i);

		ft_strupcase(str4);
		printf("up : %s \n",str4);

    ft_strlowcase(str4);
    printf("low : %s \n",str4);

		printf("capitalize : %s \n",ft_strcapitalize(str4));

		ft_strlcpy(str7,str,9);
    printf("strlcpy: %s \n",str7);

		ft_putstr_non_printable("\a hey fucker\n what \the \v fuck\r is up \e with you ");
    printf("%s \n",str4);

	return 0;
}
