/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:21:36 by ebella            #+#    #+#             */
/*   Updated: 2025/02/04 17:31:19 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	nb_nodes(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = (*stack);
	i = 0;
	while (temp && temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i + 1);
}

void	sort_2_stack(t_stack **stack)
{
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}
//sort 3 numbers in less than 3 operations
// put the smallest in b, and sort the rest in a
void	sort_3_stack(t_stack **stack)
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
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
	pa(stack, &stack_b);
	if ((*stack)->n > (*stack)->next->n)
		sa(stack); 
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
}

// sort 5 numbers in less than 12 operations
// put the smallest in b, and sort the rest in a
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
}

void	sort_small_stack(t_stack **stack, int nb_nodes)
{
    if (nb_nodes == 2)
        sort_2_stack(stack);
    else if (nb_nodes == 3)
        sort_3_stack(stack);
    else if (nb_nodes == 4)
        sort_4_stack(stack);
    else if (nb_nodes == 5)
        sort_5_stack(stack);
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
	}else
		radix_sort(&list);
    free_stack(&list);
    return (0);
}
