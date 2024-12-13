/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:21:36 by ebella            #+#    #+#             */
/*   Updated: 2024/12/13 19:53:48 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int input_is_valid(char **input)
{
    int i;
    int j;

    i = 1;
    while (input[i])
    {
        j = 0;
        while (input[i][j])
        {
            if (ft_isdigit(input[i][j]) == 0 && input[i][j] != ' ')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}


int parse_input(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    if (input_is_valid(argv) == 0)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    return (1);
}




int main(int argc, char **argv)
{
    if (parse_input(argc, argv) == 0)
        return (0);
    return (0);
}