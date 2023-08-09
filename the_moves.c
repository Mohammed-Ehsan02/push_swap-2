/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:04 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/07 22:41:18 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		second = (*stack_a)->next;
		first = *stack_a;
		tmp = first->data;
		first->data = second->data;
		second->data = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		second = (*stack_b)->next;
		first = *stack_b;
		tmp = first->data;
		first->data = second->data;
		second->data = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	int	tmp_a;
	int	tmp_b;

	if (*stack_a != NULL && (*stack_a)->next != NULL
		&& *stack_b != NULL && (*stack_b)->next != NULL)
	{
		tmp_a = (*stack_a)->data;
		tmp_b = (*stack_b)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_a)->next->data = tmp_a;
		(*stack_b)->next->data = tmp_b;
		write(1, "ss\n", 3);
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	int	tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b)->data;
	delete_the_first_node(&(*stack_b));
	if (!(*stack_a))
		create_the_node(&(*stack_a), tmp);
	else
		add_to_the_beginning(&(*stack_a), tmp);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	int	tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a)->data;
	delete_the_first_node(&(*stack_a));
	if (!(*stack_b))
		create_the_node(&(*stack_b), tmp);
	else
		add_to_the_beginning(&(*stack_b), tmp);
	write(1, "pb\n", 3);
}
