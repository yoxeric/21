/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:18:37 by yhachami          #+#    #+#             */
/*   Updated: 2023/04/05 16:21:43 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		get_biggest(int *nbrs, int size);
int		get_smallest(int *nbrs, int size);
int		in_chunk(t_stack *stk, int *nbrs, int chunk_start, int chunk_size);
int		beef_chunk(t_stack *stk, int *nbrs, int chunk_start);

void	swap(t_stack *stack, char *msg);
void	push(t_stack *stack_a, t_stack *stack_b, char *msg);
void	rotate(t_stack *stack, char *msg);
void	reverse_rotate(t_stack *stack, char *msg);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

int		ft_atoi(char *str);
char	**ft_split(char **s, char c);
int		ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
void	ft_exit(char *st);
void	ft_double_exit(char **st);

#endif
