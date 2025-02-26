/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:19:06 by ebella            #+#    #+#             */
/*   Updated: 2025/02/18 13:57:38 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	input_is_valid(char **input)
{
	int		i;
	char	*temp;

	temp = init_str(input);
	i = 0;
	if (temp[i] == '-')
		i++;
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]) && temp[i] != ' ' && (temp[i] != '-'
				|| (!ft_isdigit(temp[i + 1]) || ft_isdigit(temp[i - 1]))))
			return (free(temp), 0);
		i++;
	}
	free(temp);
	return (1);
}

char	*ft_strtok(char *str, char delim)
{
	static char	*last;
	char		*token;
	int			i;

	if (str)
		last = str;
	if (!last)
		return (NULL);
	i = 0;
	while (last[i] && last[i] != delim)
		i++;
	if (!last[i])
	{
		token = last;
		last = NULL;
		return (token);
	}
	last[i] = '\0';
	token = last;
	last = last + i + 1;
	return (token);
}

int	stack_a_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->n > current->next->n)
			return (0);
		current = current->next;
	}
	return (1);
}

int	already_appeared(t_stack *stack, long n)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->n == n)
			return (1);
		current = current->next;
	}
	return (0);
}

int	parse_input(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Error, too few args\n", 2);
		return (0);
	}
	if (!input_is_valid(argv))
	{
		ft_putstr_fd("Error, invalid input\n", 2);
		return (0);
	}
	return (1);
}
