
int	replace_var(char *name, char *value)
{
	extern char	**environ;
	int			x;
	int			y;
	int			size;
	char		*val;
	static int	malloced;
	char		*old;

	x = ft_findvar(name);
	if (x >= 0)
	{
		size = ft_strlen(name) + ft_strlen(value) + 2;
		val = (char *) malloc(size * sizeof(char));
		if (!val)
			return (0);
		y = -1;
		while (name[++y])
			val[y] = name[y];
		val[y] = '=';
		x = -1;
		while (value[++x])
			val[++y] = value[x];
		val[++y] = '\0';
		x = ft_findvar(name);
		old = environ[x];
		environ[x] = val;
		if (malloced == 1)
			free(old);
		else
			malloced = 1;
		// ft_setenv(val);
		return (0);
	}
	else
		return (-1);
}

void	ft_putenv(char *var)
{
	extern char	**environ;
	char		**new_env;
	char		*var_;
	int			x;

	x = ft_findvar(var);
	if (x == -1)
	{
		x = 0;
		while (environ[x])
			x++;
		new_env = (char **) ft_calloc((x + 2), sizeof(char *));
		if (!new_env)
			return ;
		x = -1;
		while (environ[++x])
			new_env[x] = environ[x];
		var_ = environ[--x];
		new_env[x++] = var;
		new_env[x++] = var_;
		new_env[x] = NULL;
		environ = new_env;
	}
	else
		environ[x] = var;
}

int	here_doc(char *s, int qt)
{
	int		*bibe;
	char	*input;

	bibe = (int *) malloc(2 * sizeof(int));
	if (pipe(bibe) < -1)
		return (0);
	while (1)
	{
		input = readline("> ");
		if (!input || !s || ft_strncmp(input, s, ft_strlen(input)) == 0)
			break ;
		if (*(input + count_space(input)))
		{
			if (qt == 0)
				input = replace_dollars(input);
	        write(bibe[1], input, ft_strlen(input));
	        write(bibe[1], "\n", 1);
		}
		free(input);
	}
	close(bibe[1]);
	return (bibe[0]);
}

char	*join_args(char **args, char between)
{
	int		x;
	int		i;
	int		j;
	int		size;
	char	*out;

	size = 0;
	i = -1;
	while (args[++i])
		size += ft_strlen(args[i]) + 1;
	out = (char *) malloc(size * sizeof(char));
	x = -1;
	i = -1;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
			out[++x] = args[i][j];
		out[++x] = between;
	}
	out[x] = '\0';
	return (out);
}

char	*ft_strdup_newline(char *s)
{
	int		i;
	int		size;
	char	*out;

	size = ft_strlen(s) + 1;
	out = (char *) malloc(size * sizeof(char));
	i = -1;
	while (s[++i])
		out[i] = s[i];
	out[i] = '\n';
	out[i + 1] = '\0';
	return (out);
}

int	ft_env()
{
	int			x;
	extern char	**environ;

	x = -1;
	while (environ[++x])
		ft_printf("%s\n", environ[x]);
	return (0);
}

int	ft_echo(char *arg)
{
	char	*out;
	char	flag;

	out = replace_dollars(arg);
	flag = 0;
	if (out)
		ft_printf("%s\n",out);
	else if (flag == 'n')
		ft_printf("%s\n",out);
	else if (flag == 0)
		ft_printf("%s\n",arg);
	return (0);
}

int	ft_pwd()
{
	char	*dir;
	int		i;

	dir = (char *)malloc(PATH_MAX);
	getcwd(dir, PATH_MAX);
	i = 0;
	while (dir[i])
		i++;
	dir[i++] = '\n';
	dir[i] = '\0';
	ft_printf(dir);
	free(dir);
	return (0);
}

int	ft_cd(char *arg)
{
	DIR	*dir;
	int	x;

	x = ft_strlen(arg) - 1;
	while(arg[x] == ' ')
		x--;
	arg[x + 1] = '\0';
	dir = opendir(arg);
	if (dir)
	{
		if (chdir(arg) < 0)
		{
			perror("cannot change dir");
			return (1);
		}
	}
	else
	{
		perror("dir don exist");
		return (2);
	}
	return (0);
}

int	ft_unset(char *arg)
{
	extern char	**environ;
	char		**args;
	int			x;

	args = ft_split(arg, ' ');
	x = -1;
	while (args[++x])
	{
		if (ft_findvar(args[x]) == -1)
		{
			perror("not a valid variable");
			return (1);
		}
		else
			ft_unputenv(args[x]);
	}
	return (0);
}

int	ft_export(char *arg)
{
	extern char	**environ;
	char		**args;
	int			x;

	if (!args)
		ft_env();
	args = ft_split(arg, ' ');
	x = -1;
	while (args[++x])
	{
		if (ft_isvar(args[x]) == 0)
		{
			perror("not a valid variable");
			return (1);
		}
	}
	x = -1;
	while (args[++x])
	{
		ft_putenv(args[x]);
		// ft_printf("exported = %s\n",getenv(args[x]));
	}
	// ft_env();
	// ft_unset("VR ok");
	// ft_env();
	return (0);
}

int	ft_exit()
{
	return (0);
}

int	exec_cmd(t_token token)
{
	int	out;

	out = 0;
	if (token.type == 11)
		out = ft_env();
	else if (token.type == 12)
		out = ft_pwd();
	else if (token.type == 13)
		out = ft_cd(token.arg);
	else if (token.type == 15)
		out = ft_export(token.arg);
	else if (token.type == 16)
		out = ft_unset(token.arg);
	else if (token.type == 17)
		out = ft_echo(token.arg);
	return (out);
}


//
// ls | grep a < file1 > file2
//
//           4  > file2    
//            \
//             \
//              0  |  
//             / \
//            /   \
//      ls   1     3  < file1
//                  \
//                   \
//                    2  grep
//   

//		
// ls | grep a < file1 < file2
//
//              0   |
//             / \
//            /   \
//  < file1  3     2  ls
//            \
//             \
//    < file2   4
//               \
//                \
//      grep a     1 
//

//
// /bin/ls | /usr/bin/grep c | /usr/bin/grep o
//
//              0 
//             / \
//            /   \
//           1     2
//                / \
//               /   \
//              3     4   ls
//



// int main() {
// 	t_tree	*tree;
// 	t_token	*tokens;

// 	tree = (t_tree *) malloc(sizeof(t_tree));
// 	tree->token_index = 0;
// 	tree->father = NULL;
// 	tree->right_son = NULL;
// 	tree->left_son = NULL;

// 	tree->right_son = (t_tree *) malloc(sizeof(t_tree));
// 	tree->right_son->token_index = 1;
// 	tree->right_son->father = tree;
// 	tree->right_son->right_son = 0;
// 	tree->right_son->left_son = 0;

// 	tree->left_son = (t_tree *) malloc(sizeof(t_tree));
// 	tree->left_son->token_index = 2;
// 	tree->left_son->father = tree;
// 	tree->left_son->right_son = 0;
// 	tree->left_son->left_son = 0;

// 	tree->right_son->right_son = (t_tree *) malloc(sizeof(t_tree));
// 	tree->right_son->right_son->token_index = 3;
// 	tree->right_son->right_son->father = tree->right_son;
// 	tree->right_son->right_son->right_son = 0;
// 	tree->right_son->right_son->left_son = 0;

// 	tree->right_son->left_son = (t_tree *) malloc(sizeof(t_tree));
// 	tree->right_son->left_son->token_index = 4;
// 	tree->right_son->left_son->father = tree->right_son;
// 	tree->right_son->left_son->right_son = 0;
// 	tree->right_son->left_son->left_son = 0;

// 	// tree->right_son->right_son->right_son = (t_tree *) malloc(sizeof(t_tree));
// 	// tree->right_son->right_son->right_son->token_index = 3;
// 	// tree->right_son->right_son->right_son->father = tree->left_son->left_son;
// 	// tree->right_son->right_son->right_son->right_son = 0;
// 	// tree->right_son->right_son->right_son->left_son = 0;

// 	// tree->left_son->right_son->right_son = (t_tree *) malloc(sizeof(t_tree));
// 	// tree->left_son->right_son->right_son->token_index = 3;
// 	// tree->left_son->right_son->right_son->father = tree->left_son->left_son;
// 	// tree->left_son->right_son->right_son->right_son = 0;
// 	// tree->left_son->right_son->right_son->left_son = 0;

// 	// ft_printf("treeed");

// 	tokens = (t_token *) malloc(7 * sizeof(t_token));
// 	tokens[0].type = 21;
// 	tokens[0].arg = 0;
// 	// tokens[0].arg = ft_strdup("VR=not ok=ok notok=yetok");
// 	// tokens[0].arg = ft_strdup("file1");
// 	tokens[0].in = -1;
// 	tokens[0].out = 1;

// 	tokens[1].type = 21;
// 	tokens[1].arg = 0;
// 	// tokens[1].arg = ft_strdup("/bin/ls ");
// 	tokens[1].in = -1;
// 	tokens[1].out = 1;

// 	tokens[2].type = 1;
// 	// tokens[2].arg = ft_strdup("/usr/bin/grep a");
// 	tokens[2].arg = ft_strdup("/usr/bin/grep o");
// 	tokens[2].in = 4;
// 	tokens[2].out = 1;

// 	tokens[3].type = 1;
// 	// tokens[3].arg = 0;
// 	tokens[3].arg = ft_strdup("/bin/ls");
// 	tokens[3].in = 0;
// 	tokens[3].out = 1;

// 	tokens[4].type = 1;
// 	//tokens[2].arg = 0;
// 	tokens[4].arg = ft_strdup("/usr/bin/grep c");
// 	tokens[4].in = -1;
// 	tokens[4].out = 1;

// 	tokens[5].type = 1;
// 	//tokens[2].arg = 0;
// 	tokens[5].arg = ft_strdup("/usr/bin/grep Apr");
// 	tokens[5].in = 0;
// 	tokens[5].out = 1;

// 	return (exec_node(tree, tokens));
// }
