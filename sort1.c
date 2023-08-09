/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:46:03 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/07 22:08:19 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_chunk_v2(t_node **stack_a, t_node **stack_b, int len)
{
	if (len == 2)
		sort_two_num(stack_a);
	else if (len == 3)
		sort_three_num(stack_a);
	else if (len == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (len >= 5 && len <= 34)
		sort_more(stack_a, stack_b, len);
}

void	sort_three_num(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if ((*stack_a)->data > (*stack_a)->next->next->data)
			ra(stack_a);
		else
			sa(stack_a);
	}
	else
	{
		if ((*stack_a)->data > (*stack_a)->next->next->data)
			rra(stack_a);
		else if ((*stack_a)->next->data > (*stack_a)->next->next->data)
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
}

void	sort_four_numbers(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	pos;

	min = get_smallest(*stack_a);
	pos = get_min_position(*stack_a, min);
	if (pos == 1)
	{
		sort_four_numbers_common(stack_a, stack_b);
	}
	else if (pos == 2)
	{
		sa(stack_a);
		if (is_sorted(*stack_a))
			return ;
		sort_four_numbers_common(stack_a, stack_b);
	}
	else
	{
		sort_four_con(stack_a, stack_b, pos);
	}
}

void	sort_four_numbers_common(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	sort_three_num(stack_a);
	pa(stack_a, stack_b);
}

void	sort_four_con(t_node **stack_a, t_node **stack_b, int pos)
{
	if (pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
		sort_four_numbers_common(stack_a, stack_b);
	}
	else if (pos == 4)
	{
		rra(stack_a);
		if (is_sorted(*stack_a))
			return ;
		sort_four_numbers_common(stack_a, stack_b);
	}
}
