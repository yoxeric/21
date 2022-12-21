/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:41:09 by yhachami          #+#    #+#             */
/*   Updated: 2022/11/27 00:32:30 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

typedef struct s_stack
{
   int   size;
   int   top;
   int   *items;
}           t_stack;


void  swap_a(t_stack *stack_a)
{
   int tmp;
   int top;

   top = stack_a->top;
   if (top < 1)
      return ;
   tmp = stack_a->items[top];
   stack_a->items[top] = stack_a->items[top -1];
   stack_a->items[top -1] = tmp;
   printf("\nsa\n");
}

void  swap_b(t_stack *stack_b)
{
   int tmp;
   int top;

   top = stack_b->top;
   if (top < 1)
      return ;
   tmp = stack_b->items[top];
   stack_b->items[top] = stack_b->items[top -1];
   stack_b->items[top -1] = tmp;
   printf("\nsb\n");
}

void  double_swap(t_stack *stack_a, t_stack *stack_b)
{
   swap_a(stack_a);
   swap_b(stack_b);
}

void  push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top == -1)
		return ;
	stack_a->top++;
	stack_a->items[stack_a->top] = stack_b->items[stack_b->top];
	stack_b->items[stack_b->top] = 0;
	stack_b->top--;
	printf("\npa\n");
}

void  push_b(t_stack *stack_a, t_stack *stack_b)
{
   if (stack_a->top == -1)
	   return ;
	stack_b->top++;
	stack_b->items[stack_b->top] = stack_a->items[stack_a->top];
	stack_a->items[stack_a->top] = 0;
	stack_a->top--;
	printf("\npb\n");
}

void  rotate_a(t_stack *stack_a)
{
   int   i;
   int   tmp;

   if (stack_a->top < 1)
	   return ;
   tmp = stack_a->items[stack_a->top];
   i = stack_a->top;
   while (i > 0)
   {
	   stack_a->items[i] = stack_a->items[i -1];
	   i--;
   }
   stack_a->items[0] = tmp;
   printf("\nra\n");
}

void  rotate_b(t_stack *stack_b)
{
   int   i;
   int   tmp;

   if (stack_b->top < 0)
      return ;
   tmp = stack_b->items[stack_b->top];
   i = stack_b->top;
   while (i > 0)
   {
      stack_b->items[i] = stack_b->items[i -1];
      i--;
   }
   stack_b->items[0] = tmp;
   printf("\nrb\n");
}

void  double_rotate(t_stack *stack_a, t_stack *stack_b)
{
   rotate_a(stack_a);
   rotate_b(stack_b);
   printf("\nrr\n");
}

void  reverse_rotate_a(t_stack *stack_a)
{
   int   i;
   int   tmp;

   if (stack_a->top < 1)
      return ;
   tmp = stack_a->items[0];
   i = 0;
   while (i < stack_a->top)
   {
      stack_a->items[i] = stack_a->items[i + 1];
      i++;
   }
   stack_a->items[i] = tmp;
   printf("\nrra\n");
}

void  reverse_rotate_b(t_stack *stack_b)
{
   int   i;
   int   tmp;

   if (stack_b->top < 1)
      return ;
   tmp = stack_b->items[0];
   i = 0;
   while (i < stack_b->top)
   {
      stack_b->items[i] = stack_b->items[i +1];
      i++;
   }
   stack_b->items[i] = tmp;
   printf("\nrrb\n");
}

void  double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
   reverse_rotate_a(stack_a);
   reverse_rotate_b(stack_b);
   printf("\nrrr\n");
}

void print_stack(t_stack *stack_a, t_stack *stack_b)
{
   int   i;
  
   i = stack_a->size -1;
   while (i >= 0)
   {
		printf("[%d] ", i);
	   	if (stack_a->items[i] != 0)
			printf("%d ", stack_a->items[i]);
		else
			printf("  ");
		if (stack_b->items[i] != 0)
			printf("%d ",stack_b->items[i]);
		printf("\n");
		i--;
   }
   printf("    _ _\n    a b\n");
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int x;

	i = 0;
	x = 0;
	while (i < 500)
	{
		if (stack_a->top == stack_a->size -1)
		{
			printf("--------check--------- \n");
			j = 1;
			while (j <= stack_a->top)
			{
				if (stack_a->items[j -1] < stack_a->items[j])
					break ;
				if (j == stack_a->size -1)
				{
					printf("--------done--------- %d\n", i);
					print_stack(stack_a, stack_b);
					return ;
				}
				j++;
			}
		}
		if(stack_a->items[stack_a->top] > stack_a->items[stack_a->top -1])
			swap_a(stack_a);
		else if (x == -1)
		{
			x = 0;
			reverse_rotate_a(stack_a);
		}
		else if (stack_a->top <= 1)// stack_b->top)
		{
			while (stack_a->top < stack_a->size -1)
				push_a(stack_a, stack_b);
			x = -1;
		}
		else if(stack_a->items[stack_a->top] > stack_b->items[stack_b->top])
			push_b(stack_a, stack_b);
		else
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		//printf("%d",stack_a->top);
		i++;
		print_stack(stack_a, stack_b);
	}
	printf("--------failed---------\n");
	//while (stack_a->top < stack_a->size -1)
	//	push_a(stack_a, stack_b);
}

int main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;
	int   i;

	//printf("argc = %d\n",argc);
	if (argc > 1)
	{
		stack_a.size = argc - 1;
		stack_b.size = argc - 1;
		stack_a.top = argc - 2;
		stack_b.top = -1;
		stack_a.items = (int *) malloc(argc * sizeof(int));
		stack_b.items = (int *) malloc(argc * sizeof(int));
		i = 0;
		while (i < stack_a.size)
		{
			stack_a.items[i] = argv[stack_a.size -i][0] - '0';
			stack_b.items[i] = 0;
			i++;
		}
		sort_stack(&stack_a, &stack_b);
	  /*
      swap_a(&stack_a);
      print_stack(&stack_a, &stack_b);
      push_b(&stack_a, &stack_b);
      push_b(&stack_a, &stack_b);
      push_b(&stack_a, &stack_b);
      print_stack(&stack_a, &stack_b);
      double_rotate(&stack_a, &stack_b);
	  print_stack(&stack_a, &stack_b);
      double_reverse_rotate(&stack_a, &stack_b);
      print_stack(&stack_a, &stack_b);
      swap_a(&stack_a);
      print_stack(&stack_a, &stack_b);
      push_a(&stack_a, &stack_b);
	  push_a(&stack_a, &stack_b);
      push_a(&stack_a, &stack_b);
      print_stack(&stack_a, &stack_b);
	  */
	}else
		printf("stack empty \n");
   return (0);
}
