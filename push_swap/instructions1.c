/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:22:27 by yhachami          #+#    #+#             */
/*   Updated: 2023/03/20 01:49:09 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *stack, char *msg)
{
	int	tmp;
	int	top;

	top = stack->top;
	if (top < 1)
		return ;
	tmp = stack->items[top];
	stack->items[top] = stack->items[top -1];
	stack->items[top -1] = tmp;
	if (msg)
		ft_printf("%s", msg);
}

void	push(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	if (stack_b->top == -1)
		return ;
	stack_a->top++;
	stack_a->items[stack_a->top] = stack_b->items[stack_b->top];
	stack_b->items[stack_b->top] = 0;
	stack_b->top--;
	if (msg)
		ft_printf("%s", msg);
}

void	rotate(t_stack *stack, char *msg)
{	
	int	i;
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->items[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->items[i] = stack->items[i -1];
		i--;
	}
	stack->items[0] = tmp;
	if (msg)
		ft_printf("%s", msg);
}

void	reverse_rotate(t_stack *stack, char *msg)
{
	int	i;
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->items[0];
	i = 0;
	while (i < stack->top)
	{
		stack->items[i] = stack->items[i + 1];
		i++;
	}
	stack->items[i] = tmp;
	if (msg)
		ft_printf("%s", msg);
}
