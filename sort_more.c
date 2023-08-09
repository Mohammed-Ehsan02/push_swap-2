/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:16:48 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/07 14:52:54 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_cont(t_node **stack_a, t_node **stack_b, int i)
{
	while (i)
	{
		pa(stack_a, stack_b);
		i--;
	}
}

	// int		smallest; i[0]
	// int		smallest_position; i[1]

void	sort_more(t_node **stack_a, t_node **stack_b, int count)
{
	int		i[2];
	int		total;
	int		current_a;

	count = 0;
	total = lst_size(*stack_a);
	i[0] = get_smallest(*stack_a);
	i[1] = get_min_position(*stack_a, i[0]);
	while (1)
	{
		current_a = lst_size(*stack_a);
		if (current_a == 4)
			break ;
		i[0] = get_smallest(*stack_a);
		if ((*stack_a)->data == i[0])
		{
			pb(stack_a, stack_b);
			count++;
		}
		else if (i[1] < total / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_four_more(stack_a, stack_b, count);
}

void	sort_four_more(t_node **stack_a, t_node **stack_b, int count)
{
	sort_four_numbers(stack_a, stack_b);
	sort_more_cont(stack_a, stack_b, count);
}
