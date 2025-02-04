/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:55:55 by ebella            #+#    #+#             */
/*   Updated: 2025/02/04 17:28:34 by ebella           ###   ########.fr       */
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

void	radix_sort(t_stack **stack_a)
{

}