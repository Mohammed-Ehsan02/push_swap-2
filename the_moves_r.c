/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:07:13 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/07 22:05:55 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	(*stack_a) = (*stack_a)->next;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	(*stack_b) = (*stack_b)->next;
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	(*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
	write(1, "rr\n", 3);
}

void	rra(t_node **stack_a)
{
	(*stack_a) = (*stack_a)->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	(*stack_b) = (*stack_b)->prev;
	write(1, "rrb\n", 4);
}
