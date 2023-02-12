/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 05:55:22 by yhachami          #+#    #+#             */
/*   Updated: 2022/11/24 22:49:36 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

char		*get_next_line(int fd);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
int			get_nl(char *s);
void		*ft_calloc(size_t count, size_t size);

#endif
