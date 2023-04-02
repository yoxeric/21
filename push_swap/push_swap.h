/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:18:37 by yhachami          #+#    #+#             */
/*   Updated: 2023/03/20 01:56:22 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct s_stack
{
	int	size;
	int	top;
	int	*items;
}		t_stack;

int		*get_stack(char **av, t_stack *sa, t_stack *sb);
void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *nbrs);
void	print_stack(t_stack *stack_a, t_stack *stack_b);

void	swap(t_stack *stack, char *msg);
void	push(t_stack *stack_a, t_stack *stack_b, char *msg);
void	rotate(t_stack *stack, char *msg);
void	reverse_rotate(t_stack *stack, char *msg);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

int		ft_atoi(const char *str);
char	**ft_split(char **s, char c);
int		ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
void	ft_exit(int id);

#endif
