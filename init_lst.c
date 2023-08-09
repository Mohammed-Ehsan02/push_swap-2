/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:45:36 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/09 21:36:39 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_s(t_node **stack_a, char *s)
{
	int		i;
	int		x;
	char	**array;

	i = 0;
	x = 1;
	array = ft_split(s, ' ');
	if (!array || !array[0])
	{
		write (2, "Error\n", 6);
		exit(0);
	}
	create_the_node(&(*stack_a), ft_atoil(array, array[0], s));
	while (array[x])
	{
		add_end(stack_a, ft_atoil(array, array[x], s));
		x++;
	}
	i = 0;
	while (array[i])
	{
		free(array[i]); 
		i++;
	}
	free(array);
}

void	ft_init_list(t_node **node, char **av)
{
	int	i;

	i = 1;
	create_the_node(&(*node), ft_atoi(av[i]));
	while (av[++i])
	{
		add_end(&(*node), ft_atoi(av[i]));
	}
}

int	get_smallest(t_node *head)

{
	t_node	*current;
	int		list_size;
	int		smallest_value;
	int		index;

	if (head == NULL)
		return (0); 
	index = 0;
	current = head;
	list_size = lst_size(head);
	smallest_value = head->data;
	while (index < list_size) 
	{
		if (current->data < smallest_value)
			smallest_value = current->data;
		current = current->next;
		index++;
	}
	return (smallest_value);
}

int	get_maximum(t_node *s)
{
	t_node	*tmp;
	int		size;
	int		max;
	int		i;

	if (s == NULL)
		return (0);
	tmp = s;
	size = lst_size(s);
	max = s->data;
	i = 0;
	while (i < size)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
		}
		tmp = tmp->next;
		i++;
	}
	return (max);
}

int	get_min_position(t_node *n, int min)
{
	t_node	*tmp;
	int		pos;
	int		i;
	int		size;

	size = lst_size(n);
	tmp = n;
	pos = 1;
	i = 0;
	while (i < size)
	{
		if (tmp->data == min)
			break ;
		tmp = tmp->next;
		pos++;
		i++;
	}
	return (pos);
}
