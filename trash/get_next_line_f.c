/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:27:31 by yhachami          #+#    #+#             */
/*   Updated: 2022/11/16 00:36:52 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

// char	*save_next(char **next, char *str)
// {
// 	int	i;
//
// 	if (!str || !str[0])
// 	{
// 		if (next)
// 			free(next);
// 		return (NULL);
// 	}
// 	if (!(*next))
// 	{
// 		*next = (char *) malloc(BUFFER_SIZE + 1);  // need free
// 		if (!(*next))
// 			return (NULL);
// 	}
// 	i = 0;
// 	while (str[i])
// 	{
// 		(*next)[i] = str[i];
// 		i++;
// 	}
// 	(*next)[i] = '\0';
// 	return (*next);
// }

char *get_line(char *line, char *buf, char **next)
{
	char	*s;
	int		i;

	i = -1;
	while (buf[++i])
		if (buf[i] == '\n')
			break ;
	// if (i == 0)
	// 	free(*next);
	s = (char *) malloc(i + 2);
	i = -1;
	while (buf[++i])
	{
		s[i] = buf[i];
		if (s[i] == '\n')
		{
			if (buf[i + 1])
				*next = ft_strdup(&buf[i + 1]);
			break ;
		}
	}
	s[i + 1] = '\0';
	if (!line || !line[0])
		return (s);
	else
		return (ft_strjoin(line,s));
}

char *get_prev(char **next, int *l)
{
	char	*line;
	int		i;

	if (!(*next) || !(*next)[0])
		return (NULL);
	line = (char *) malloc(ft_strlen(*next) + 2); // need to be free?
	if (!line)
		return (NULL);
	i = 0;
	while ((*next)[i])
	{
		line[i] = (*next)[i];
		if (line[i] == '\n') // && (*next)[i + 1]
		{
			i++;
			*next += i;
			// *next = save_next(next, &line[i + 1]);
			*l = -1;
			break ;
		}
		i++;
	}
	line[i] = '\0';
	// if (i == ft_strlen(*next))
	// 	free(*next);
	return (line);
}

char	*get_next_line(int fd)
{
	static char*	next;
	char		buf[BUFFER_SIZE + 2];
	char		*line;
	int			l;

	if (fd < 0 || fd > 1024)
		return (NULL);
	l = 1;
	line = get_prev(&next, &l);
	if (l == -1)
		return (line);
	while (l > 0)
	{
		l = read(fd, buf, BUFFER_SIZE);
		if (l <= 0)
		{
			if (next)
				free(next);
			free(line);
			return(NULL);
		}
		buf[l] = '\0';
		line = get_line(line, buf, &next);
		if (ft_strchr(line,'\n'))
			break;
	}
	return (line);
}

// int main()
// {
// 	int fd;
//
// 	fd = open("foo.txt",O_RDONLY);
// 	printf("1:%s",get_next_line(fd));
// 	printf("2:%s",get_next_line(fd));
// 	printf("3:%s",get_next_line(fd));
// 	printf("4:%s",get_next_line(fd));
// 	printf("5:%s",get_next_line(fd));
// 	printf("6:%s",get_next_line(fd));
// 	printf("7:%s",get_next_line(fd));
// 	printf("8:%s",get_next_line(fd));
// 	close(fd);
// 	return 0;
// }
