/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:00:53 by ebella            #+#    #+#             */
/*   Updated: 2025/02/17 12:28:12 by ebella           ###   ########.fr       */
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
