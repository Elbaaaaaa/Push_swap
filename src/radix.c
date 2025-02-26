/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:55:55 by ebella            #+#    #+#             */
/*   Updated: 2025/02/26 15:27:06 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	current = stack;
	max = current->n;
	while (current)
	{
		if (current->n > max)
			max = current->n;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*current;

	current = stack;
	min = current->n;
	while (current)
	{
		if (current->n < min)
			min = current->n;
		current = current->next;
	}
	return (min);
}

void	normalize_values(t_stack **stack_a)
{
	t_stack		*current;
	t_stack		*temp;
	int			j;

	current = *stack_a;
	while (current)
	{
		temp = *stack_a;
		j = 0;
		while (temp)
		{
			if (current->n > temp->n)
				j++;
			temp = temp->next;
		}
		current->normalized = j;
		current = current->next;
	}
}

void	radix_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;
	int		size;

	normalize_values(stack_a);
	stack_b = NULL;
	i = 0;
	while (stack_a_sorted(*stack_a) == 0)
	{
		size = nb_nodes(stack_a);
		while (size--)
		{
			if (((*stack_a)->normalized >> i & 1) == 0)
				pb(stack_a, &stack_b);
			else
				ra(stack_a);
		}
		while (stack_b)
			pa(stack_a, &stack_b);
		i++;
	}
}
