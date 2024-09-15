
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//#include <stdio.h>

void	exec(char **arg, char **env, int tmp, int end)
{
	if (arg[end])
		arg[end] = NULL;
	dup2(tmp, 0);
	close(tmp);
	execve(arg[0], arg, env);
	write(2,"error: cannot execute ",22);
	write(2, arg[0], strlen(arg[0]));
	write(2,"\n",1);
}

int main(int ac, char **av, char **env)
{
    int x;
    int y;
    int size;
    int type;
    int     p[2];
	int		tmp;
	int		pid;

    x = 1;
	tmp = dup(0);
    while (x < ac)
    {
        y = x;
        type = 0;
        while (av[y] && strcmp(av[y],"|") != 0 && strcmp(av[y],";") != 0)
            y++;
        if (av[y] && strcmp(av[y],"|") == 0)
             type = 1;
        if (av[y] && strcmp(av[y],";") == 0)
             type = 3;
		if (y == ac)
			type = 2;
        size = y - x;
        //printf("[%d] %s => [%d] %s     size = (%d)\n", x, av[x] , y, av[y], size);

		if (strcmp(av[x],"cd") == 0)
		{
        	if (size == 2)
			{
            	if (chdir(av[x + 1]) != 0)
				{
					write(2,"error: cannot execute ",22);
					write(2,av[x],strlen(av[x]));
					write(2,"\n",1);
				}
			}
			else
            	write(2, "error: cd: bad arguments\n", 25);
		}
		else if (size > 0)
		{
			if (type == 1)
				pipe(p);
			pid = fork();
			if (pid < 0)
			{
				write(2,"error: fatal\n" ,13);
				exit(1);
			}
			if (pid == 0)
			{
				if (type == 1)
				{
					dup2(p[1], 1);
					close(p[1]);
					close(p[0]);
				}
				exec(&av[x], env, tmp, size);
			}
			else
			{
				if (type == 2 || type == 3)
				{
					close(tmp);
					waitpid(pid, NULL, 0);
					tmp = dup(0);
				}
				if (type == 1)
				{
					close(p[1]);
					close(tmp);
					tmp = p[0];
				}
			}
		}
        x += size + 1;
    }
	close(tmp);
}
