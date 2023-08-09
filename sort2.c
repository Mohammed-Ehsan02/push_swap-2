/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:20:51 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/08 15:34:28 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium_chunk(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	chunksize;
	int	remainingelements;
	int	i;
	int	j;

	size = lst_size(*stack_a);
	chunksize = size / 4;
	remainingelements = size % 4;
	i = 0;
	while (i < size - remainingelements)
	{
		j = i + chunksize - 1;
		push_the_chunk(stack_a, stack_b, i, j);
		i = j + 1;
	}
	if (remainingelements == 3)
	{
		sort_three_num(stack_a);
	}
	else if (remainingelements > 0)
	{
		sort_more(stack_a, stack_b, i);
	}
	sort_the_push_chunk(stack_a, stack_b);
}

void	push_the_chunk(t_node **stack_a, t_node **stack_b, int min, int max)
{
	int	size;
	int	half_range;

	half_range = (min + max) / 2;
	while (1)
	{
		if ((*stack_a)->data >= min && (*stack_a)->data <= max)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->data <= half_range)
				rb(stack_b);
		}
		else
			ra(stack_a);
		if (*stack_b)
		{
			size = lst_size(*stack_b);
			if (size == max + 1)
				break ;
		}
	}
}

void	sort_the_push_chunk(t_node **stack_a, t_node **stack_b)
{
	int	b_size;
	int	max_value;
	int	max_value_pos;
	int	mid_position;

	while (1)
	{
		max_value = get_maximum(*stack_b);
		max_value_pos = get_min_position(*stack_b, max_value);
		b_size = lst_size(*stack_b);
		mid_position = b_size / 2;
		if ((*stack_b)->data == max_value)
			pa(stack_a, stack_b);
		else if (max_value_pos <= mid_position)
			rb(stack_b);
		else
			rrb(stack_b);
		if (b_size == 2)
			break ;
	}
	if ((*stack_b)->data < (*stack_b)->next->data)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_large_chunk(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	min;
	int	max;
	int	i;

	i = 0;
	size = lst_size(*stack_a);
	min = size / 9;
	min--;
	max = min;
	while (max < size - 11)
	{
		push_the_chunk(stack_a, stack_b, i - 1, max + 4);
		i = max + 2;
		max += min;
	}
	sort_more(stack_a, stack_b, i);
	sort_the_push_chunk(stack_a, stack_b);
}
