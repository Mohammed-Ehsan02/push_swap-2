/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:50:58 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/07 21:37:01 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_the_node(t_node **top, int form)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = form;
	new_node->prev = new_node;
	new_node->next = new_node;
	(*top) = new_node;
}

void	add_end(t_node **top, int form)
{
	t_node	*new_node;
	t_node	*last_node;

	create_the_node(&new_node, form);
	if (new_node == NULL)
		return ;
	if (*top == NULL)
	{
		*top = new_node;
		return ;
	}
	last_node = (*top)->prev;
	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->next = *top;
	(*top)->prev = new_node;
}

void	add_to_the_beginning(t_node **top, int form)
{
	t_node	*new_node;

	create_the_node(&new_node, form);
	if (new_node == NULL)
		return ;
	if (*top == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = *top;
		new_node->prev = (*top)->prev;
		(*top)->prev->next = new_node;
		(*top)->prev = new_node;
	}
	*top = new_node;
}

int	lst_size(t_node *n)
{
	int	size;
	int	data;

	size = 1;
	data = n->data;
	n = n->next;
	while (data != n->data)
	{
		size++;
		n = n->next;
	}
	return (size);
}

void	delete_the_first_node(t_node **n)
{
	t_node	*tmp;

	tmp = *n;
	if (*n == NULL)
		return ;
	if ((*n)->next == *n)
	{
		free(*n);
		*n = NULL;
	}
	else
	{
		(*n)->next->prev = (*n)->prev;
		(*n)->prev->next = (*n)->next;
		*n = (*n)->next;
		free(tmp);
	}
}
