/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:31:52 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/08 21:25:11 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_sort(t_node **stack_a, t_node **stack_b, t_node **tmpa)
{
	if (is_sorted(*stack_a))
	{
		ft_free(stack_a);
		return (0);
	}
	sort_list(stack_a, stack_b, tmpa);
	ft_free(stack_a);
	ft_free(tmpa);
	return (1);
}

int	is_sorted(t_node *node)
{
	int		i;
	int		size;
	t_node	*tmp;

	i = 0;
	size = lst_size(node);
	tmp = node;
	while (i < size - 1)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	sort_list(t_node **stack_a, t_node **stack_b, t_node **tmpa)
{
	int	len;

	(void)stack_b;
	len = lst_size(*stack_a);
	if (len <= 34)
	{
		ft_init_alias(stack_a, tmpa);
		small_chunk_v2(tmpa, stack_b, len);
	}
	else if (len <= 134)
	{
		ft_init_alias(stack_a, tmpa);
		sort_medium_chunk(tmpa, stack_b);
	}
	else
	{
		ft_init_alias(stack_a, tmpa);
		sort_large_chunk(tmpa, stack_b);
	}
}

void	sort_two_num(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}
