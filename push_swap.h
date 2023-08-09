/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:39:02 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/09 22:21:22 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}					t_node;

// parsing
char		**ft_split(char const *s, char c);
int			ft_atoi(char *str);
int			ft_atoil(char **tab, char *str, char *origin);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			is_sign(char **av);
int			is_alpha(char **tab);
int			is_similar(char **av);
int			sign_str(char **av);
int			is_alpha_str(char **av);
int			is_similar_str(char **av, char *str);
void		ft_check_error_con(char *args);
void		create_the_node(t_node **top, int form);
void		ft_check_error(char *args);
void		free_lst(char **tab, char *str);

// list
void		ft_init_list(t_node **node, char **av);
void		ft_init_s(t_node **stack_a, char *s);
void		ft_free(t_node **stack_a);
int			lst_size(t_node *n);
void		ft_init_s(t_node **stack_a, char *s);
void		calculate_alias_counts(t_node *node, int *counts, int size);
void		ft_init_alias(t_node **node, t_node **alias);
void		sort_list(t_node **stack_a, t_node **stack_b, t_node **tmpa);
void		ft_init_s(t_node **stack_a, char *s);
void		add_end(t_node **top, int form);
void		delete_the_first_node(t_node **n);
void		add_to_the_beginning(t_node **top, int form);
void		custom_alias(t_node **alias, int data);
// move
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
// sort
void		sort_medium_chunk(t_node **stack_a, t_node **stack_b);
void		push_the_chunk(t_node **stack_a, t_node **stack_b,
				int min, int max);
void		sort_the_push_chunk(t_node **stack_a, t_node **stack_b);
void		sort_large_chunk(t_node **stack_a, t_node **stack_b);
int			start_sort(t_node **stack_a, t_node **stack_b, t_node **tmpa);
int			is_sorted(t_node *node);
void		small_chunk_v2(t_node **stack_a, t_node **stack_b, int len);
void		sort_three_num(t_node **stack_a);
void		sort_two_num(t_node **stack_a);
void		sort_four_numbers(t_node **stack_a, t_node **stack_b);
void		sort_four_numbers_common(t_node **stack_a, t_node **stack_b);
void		sort_four_con(t_node **stack_a, t_node **stack_b, int pos);
void		sort_more_cont(t_node **stack_a, t_node **stack_b, int i);
int			get_smallest(t_node *head);
int			get_min_position(t_node *n, int min);
int			get_maximum(t_node *s);
void		ft_init_alias(t_node **node, t_node **alias);
void		sort_more(t_node **stack_a, t_node **stack_b, int count);
void		sort_four_more(t_node **stack_a, t_node **stack_b, int count);
int continu(char **argv);


#endif
