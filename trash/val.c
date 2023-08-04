
#include"minishell.h"

int	ft_minishell_valgrind()
{
	char	*input;
	int		ex;
	int fd = open("AAAAA", O_RDONLY);
	t_token	*nodes;
	t_tree	*tree;

	ex = 1;
	tree = NULL;
	nodes = NULL;
	shvlvl();
	*g_error = 0;
	while (ex)
	{
		input = get_next_line(fd);
		if (!input)
			break ;
		ft_printf(">>> MiniShell $> %s", input);
		if (input[count_space(input)])
		{
			input[ft_strlen(input) - 1] = '\0';
			nodes = split_input(input, &ex);
			if (nodes)
			{
				tree = create_tree(nodes, ex);
				//treeprint(tree, 0, nodes);
				// ft_printf("\n------EXEC-----\n");
				exec_tree(tree, nodes);
				free_tree(tree, nodes);
				free(nodes);
				// free_struct_array(NULL, NULL, nodes, ex);
				ex = 1;
			}
		}
		free(input);
		// system("leaks minishell");
	}
	return(*g_error);
}

int	here_file(char *s, int qt)
{
	int		tmp;

	(void)(qt);
	tmp = open(s, O_WRONLY | O_CREAT | O_EXCL| O_TRUNC, 0644);
	if (tmp < 0)
		return (-1);
			write(tmp, "AAAAAAAAAAA", 11);
			write(tmp, "\n", 1);
	close(tmp);
	return (0);
}

int	main(int ac, char **av)
{
	char	*in;
	t_token	*nodes;
	t_tree	*tree;
	int		ex;
	int		out;

	ex = 1;
	tree = NULL;
	nodes = NULL;
	g_error = (int *) malloc(1 * sizeof(int));
	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		in = av[2];
		if (*(in + count_space(in)))
		{
			shvlvl();
			nodes = split_input(in, &ex);
			if (!nodes)
				return (*g_error);
			if (nodes)
			{
				tree = create_tree(nodes, ex);
				//treeprint(tree, 0, nodes);
				// ft_printf("\n------EXEC-----\n");
				exec_tree(tree, nodes);
				free_tree(tree, nodes);
				free(nodes);
				// free_struct_array(NULL, NULL, nodes, ex);
				ex = 1;
			}
		}
		return (*g_error);
	}
	else
	{
		ft_minishell();
		out = *g_error;
		free(g_error);
	}
	return (out);
}

// ./minishell

// ENV

// unset ""

// unset $""

// clear