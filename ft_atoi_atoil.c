/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_atoil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:20:40 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/09 21:15:58 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_overflow(size_t result, int sign, char *str)
{
	if (result > 2147483647 && sign == 1)
	{
		write(2, "Error\n", 6);
		free(str);
		exit(0);
	}
	if (result > 2147483648 && sign == -1)
	{
		write(2, "Error\n", 6);
		free(str);
		exit(0);
	}
}

int	ft_atoi(char *str)
{
	size_t		result;
	size_t		temp_result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp_result = result;
		result = result * 10 + str[i++] - '0';
		if (temp_result > result)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	ft_atoi_overflow(result, sign, str);
	return (result * sign);
}

void	ft_atoil_overflow(size_t result, int sign, char **tab, char *origin)
{
	if (result > 2147483647 && sign == 1)
	{
		free_lst(tab, origin);
		exit(0);
	}
	if (result > 2147483648 && sign == -1)
	{
		free_lst(tab, origin);
		exit(0);
	}
}

int	ft_atoil(char **tab, char *str, char *origin)
{
	size_t		result;
	size_t		temp_result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp_result = result;
		result = result * 10 + str[i++] - '0';
		if (temp_result > result)
		{
			free_lst(tab, origin);
			exit(0);
		}
	}
	ft_atoil_overflow(result, sign, tab, origin);
	return (result * sign);
}
