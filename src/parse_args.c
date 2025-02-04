/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:19:06 by ebella            #+#    #+#             */
/*   Updated: 2025/02/04 17:17:02 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*init_str(char **input)
{
	char	*str;
	char	*temp;
	int		i;
	size_t	len;

	str = ft_strdup("");
	i = 1;
	while (input[i])
	{
		len = ft_strlen(str) + ft_strlen(input[i]) + 2;
		temp = (char *)malloc(len * sizeof(char));
		if (!temp)
			return (free(temp), NULL);
		ft_strlcpy(temp, str, len);
		ft_strlcat(temp, input[i], len);
		free(str);
		str = temp;
		if (input[i + 1])
			ft_strlcat(temp, " ", len);
		i++;
	}
	return (str);
}

int	init_list(t_stack **list, char *str)
{
	char	*token;
	long	nbr;

	token = ft_strtok(str, ' ');
	while (token)
	{
		nbr = ft_atol_stack(token);
		if (already_appeared(*list, nbr))
			return (free_stack(list), free(str), ft_putstr_fd("Error\n", 2), 0);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (free_stack(list), free(str), ft_putstr_fd("Error\n", 2), 0);
		ft_lstadd_back_stack(list, ft_lstnew_stack(nbr));
		token = ft_strtok(NULL, ' ');
	}
	free(str);
	return (1);
}

int	input_is_valid(char **input)
{
	int		i;
	char	*temp;

	temp = init_str(input);
	i = 0;
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]) && temp[i] != ' ' && (temp[i] != '-'
				|| (!ft_isdigit(temp[i + 1]) || ft_isdigit(temp[i - 1]))))
			return (0);
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
// checks if the stack of numbers is already sorted.
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
