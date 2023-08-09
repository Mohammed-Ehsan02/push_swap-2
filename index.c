/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:33:04 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/09 21:22:04 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	custom_alias(t_node **alias, int data)
{
	if (!(*alias))
		create_the_node(alias, data);
	else
		add_end(alias, data);
}

void	ft_init_alias(t_node **node, t_node **alias)
{
	int	size;
	int	*counts;
	int	i;

	size = lst_size(*node);
	counts = malloc(size * sizeof(int));
	calculate_alias_counts(*node, counts, size);
	i = 0;
	while (i < size)
	{
		custom_alias(alias, counts[i]);
		i++;
	}
	free(counts);
}

void	calculate_alias_counts(t_node *node, int *counts, int size)
{
	t_node	*tmp;
	t_node	*current;
	int		i[2];
	int		x;
	int		j;

	tmp = node;
	x = 0;
	while (x < size)
	{
		j = 0;
		i[0] = tmp->data;
		i[1] = 0;
		current = node;
		while (j < size)
		{
			if (i[0] > current->data)
				i[1]++;
			current = current->next;
			j++;
		}
		counts[x] = i[1];
		tmp = tmp->next;
		x++;
	}
}

void	ft_free(t_node **a)
{
	int		size;
	t_node	*tmp;
	t_node	*tmp1;

	tmp = (*a);
	tmp1 = tmp;
	size = lst_size(*a);
	while (size)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
		size--;
	}
}

void	free_lst(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(str);
	write(2, "list Error\n", 12);
}
