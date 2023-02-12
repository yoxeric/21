#include<stdio.h>

void rempli_tableau(char T[], int dim)
{
	int i;

	printf("rnter le nobre:");
	for (i=0;i<dim;i++)
		scanf("%c",T[i]);
	return;
}

int	main()
{
	int zbi;
	int x = 0;
	int y;
	int z;

	printf("enter le nombre des valeurs : ");
	scanf("%d",&z);
	y = 1;	//for(x = 0;x < 10; x++)
	while(x < z)
	{
		printf("enter un valeur : ");
		scanf("%d",&zbi);
		//zbi = zbi + 10;
		y = y * zbi;
		printf("result : %d \n ",y);
		x++;
	}
	printf("result : %d \n ",y);
	return 0;
}
