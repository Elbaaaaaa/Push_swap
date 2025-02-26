/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:21:36 by ebella            #+#    #+#             */
/*   Updated: 2025/02/18 12:22:06 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2_stack(t_stack **stack)
{
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}

void	sort_3_stack(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->n;
	b = (*stack)->next->n;
	c = (*stack)->next->next->n;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c && a > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a < b && b < c && a < c)
		return ;
}

void	sort_4_stack(t_stack **stack)
{
	int		min;
	t_stack	*stack_b;

	stack_b = NULL;
	min = find_min(*stack);
	while ((*stack)->n != min)
		ra(stack);
	if (stack_a_sorted(*stack))
		return ;
	pb(stack, &stack_b);
	sort_3_stack(stack);
	pa(stack, &stack_b);
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}

void	sort_5_stack(t_stack **stack)
{
	int		min;
	t_stack	*stack_b;

	stack_b = NULL;
	min = find_min(*stack);
	while ((*stack)->n != min)
		ra(stack);
	if (stack_a_sorted(*stack))
		return ;
	pb(stack, &stack_b);
	sort_4_stack(stack);
	pa(stack, &stack_b);
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}

int	main(int argc, char **argv)
{
	int		nb;
	char	*str;
	t_stack	*list;

	list = NULL;
	if (parse_input(argc, argv) == 0)
	{
		return (0);
	}
	str = init_str(argv);
	if (!init_list(&list, str))
		return (0);
	nb = nb_nodes(&list);
	if (nb <= 5)
	{
		while (stack_a_sorted(list) == 0)
			sort_small_stack(&list, nb);
	}
	else
		radix_sort(&list);
	free_stack(&list);
	return (0);
}
