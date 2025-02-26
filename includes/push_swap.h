/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:19:15 by ebella            #+#    #+#             */
/*   Updated: 2025/02/26 15:26:52 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				n;
	int				normalized;
	struct s_stack	*next;
}					t_stack;

int					input_is_valid(char **input);
int					parse_input(int argc, char **argv);
int					main(int argc, char **argv);
char				*init_str(char **input);
int					init_list(t_stack **list, char *str);
char				*ft_strtok(char *str, char delim);
t_stack				*ft_lstnew_stack(long content);
t_stack				*ft_lstlast_stack(t_stack *lst);
void				ft_lstadd_back_stack(t_stack **lst, t_stack *new);
long				ft_atol_stack(const char *str);
void				free_stack(t_stack **stack);
int					already_appeared(t_stack *list, long nbr);
int					nb_nodes(t_stack **stack);
int					stack_a_sorted(t_stack *stack);
void				sort_small_stack(t_stack **stack, int nb_nodes);
void				sort_2_stack(t_stack **stack);
void				sort_3_stack(t_stack **stack);
void				sort_4_stack(t_stack **stack);
void				sort_5_stack(t_stack **stack);
void				radix_sort(t_stack **stack_a);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
void				normalize_values(t_stack **stack_a);

/*							OPERATIONS								*/
void				sa(t_stack **list);
void				ra(t_stack **list);
void				rra(t_stack **stack);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);

#endif