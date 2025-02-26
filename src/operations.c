/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:22:41 by ebella            #+#    #+#             */
/*   Updated: 2025/02/17 12:28:41 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swap the two top elements of stack a
void	sa(t_stack **list)
{
	t_stack	*temp;

	if (!*list || !(*list)->next)
		return ;
	temp = *list;
	*list = (*list)->next;
	temp->next = (*list)->next;
	(*list)->next = temp;
	ft_putstr_fd("sa\n", 1);
}

// Top number in B is moved to the top of A
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putstr_fd("pa\n", 1);
}

// Top number in A is moved to the top of B
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_putstr_fd("pb\n", 1);
}

// Top number in A goes to the bottom of A
void	ra(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back_stack(stack, temp);
	ft_putstr_fd("ra\n", 1);
}

// Bottom number in A goes to top of A
void	rra(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_last;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack);
	while ((temp->next)->next)
		temp = temp->next;
	temp_last = temp->next;
	temp->next = NULL;
	temp_last->next = (*stack);
	*stack = temp_last;
	ft_putstr_fd("rra\n", 1);
}
