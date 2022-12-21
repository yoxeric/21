#include<stdio.h>
#include <string.h>

char *ft_strdup(char *src);
int *ft_range(int min, int max);
int ft_ultimate_range(int **range, int min, int max);
char *ft_strjoin(int size, char **strs, char *sep);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
char **ft_split(char *str, char *charset);


int main()
{
	int i;
	char *s;
	char *s1;
	int *s2;
	int *s3;
	char *s4[3];

	s = ft_strdup("nice");
	printf("%s\n",s);
    s1 = strdup("nice");
    printf("%s\n",s1);


    s2 = ft_range(5,10);
	i = 0;	
	while (s2[i])
	{
    	printf("%d\n",s2[i]);
		i++;
	}

	ft_ultimate_range(&s3,2,7);
    i = 0;
    while (s3[i])
    {
        printf("%d\n",s3[i]);
        i++;
    }


    s4[0] = "helo";
	s4[1] = "feoa";

	s = ft_strjoin(2,s4,"-");
    i = 0;
    printf("%s\n",s);
}
