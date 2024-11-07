#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

int main(int ac, char **av, char **env)
{
    int x;
    int y;
    int size;
    int i;
    int type;
    int prev_type;
    char    **args;
    int     p[2];

    printf("            ac = %d\n", ac);
    x = 1;
    pipe(p);
    prev_type = 0;
    while (x < ac)
    {
        printf("            x = %d\n", x);
        y = x;
        type = 0;
        while (av[y])
        {
            if (strcmp(av[y],"|") == 0)
            {
                type = 1;
                break;
            }
            if (strcmp(av[y],";") == 0)
            {
                type = 2;
                break;
            }
            y++;
        }
        size = y - x;
        printf("[%d] %s => [%d] %s\n", x, av[x] , y, av[y]);
        printf("size = %d\n", size);
        args = (char **) malloc(size * sizeof(char *));
        i = 0;
        while (i < size && x + i < ac)
        {
            args[i] = av[x + i];
            printf("   args => [%d] %s\n", i, av[x + i]);
            i++;
        }
        if (size > 0 && fork() == 0)
        {
            if (type == 1)
                dup2(p[1], 1);
            if (prev_type == 1)
                dup2(p[0], 0);
            execve(av[x], args, env);
            write(2,"error: cannot execute ",22);
            write(2,av[x],strlen(av[x]));
            write(2,"\n",1);
        }
        free(args);
        x += i + 1;
        prev_type = 1;
    }
}
