/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:38:22 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/09 21:08:24 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	sign_str(char **av)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (av[i])
	{
		x = 0;
		while (av[i][x])
		{
			if (x == 0 && (av[i][x] == '-' || av[i][x] == '+'))
				x++;
			if (!ft_isdigit(av[i][x]))
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int	is_alpha_str(char **tab)
{
	int	i;
	int	x;

	i = 0;
	while (tab[i] != NULL)
	{
		x = 0;
		while (tab[i][x] != '\0')
		{
			if (ft_isalpha(tab[i][x]))
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int	is_similar_str(char **av, char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (av[i])
	{
		x = i + 1;
		while (av[x])
		{
			if (ft_atoil(av, av[i], str) == ft_atoil(av, av[x], str))
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

void	ft_check_error_con(char *av)
{
	char	**tab;
	int i;

	i = 0;
	if (av[1] == 0)
	{
		free(av);
		exit(0);
	}
	tab = ft_split(av, ' ');
	if (sign_str(tab) || is_alpha_str(tab) || is_similar_str(tab, av))
	{
		while (tab[i])
			free(tab[i++]); 
		free(tab);
		free(av);
		write(2, "Errooooooor\n", 13);
		exit(1);
	}
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
