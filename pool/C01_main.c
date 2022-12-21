#include<unistd.h>
#include<stdio.h>

void ft_ft(int *nbr);
void ft_ultimate_ft(int *********nbr);
void ft_swap(int *a, int *b);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_ultimate_div_mod(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
void ft_rev_int_tab(int *tab, int size);
void ft_sort_int_tab(int *tab, int size);

int main()
{
	int *a ; 
	int i =	5;
	int *b; 
	int j = 13;
	int *c;
	int k = 4;
	int *d;
	int z = 7;
	char str[11] = "hello wrrld";
	int tab[7] = {8,4,2,3,4,7,6};

	a = &i;
	b = &j;
	c = &k;
	d = &z;

	ft_ft(a);
	printf("\n %d \n",*a );

	i = 1750;	
	int *p1 = &i;
	int **p2 = &p1;
	int ***p3 = &p2;
    int ****p4 = &p3;
    int *****p5 = &p4;
    int ******p6 = &p5;
    int *******p7 = &p6;
    int ********p8 = &p7;
	ft_ultimate_ft(&p8);
    printf("%d\n", i);
	
	ft_swap(c, d);
    printf("%d ,%d \n",*a , *b );  
	
	ft_div_mod(i, j, c, d);
    printf("%d ,%d \n",*c , *d );
	
	ft_ultimate_div_mod(a, b);
    printf("%d ,%d \n",*a , *b);

	ft_putstr(str);
    printf("\n");

	int u = ft_strlen(str);
	printf("%d \n",u);

	i=0;
	while(i<7){
		printf("%d",tab[i]);
		i++;
	}	
    printf("\n");
	ft_rev_int_tab(tab, 7);
	i=0;
    while(i<7){
        printf("%d",tab[i]);
        i++;
	}
    printf("\n");

	ft_sort_int_tab(tab, 7);
    i=0;
    while(i<7){
        printf("%d",tab[i]);
        i++;
    }
}
