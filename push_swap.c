/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:10:03 by aalbobak          #+#    #+#             */
/*   Updated: 2023/08/09 22:22:02 by aalbobak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char *s2, bool flag)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i++] = s2[j];
		j++;
	}
	str[i] = '\0';
	if (flag == true)
		free(s1);
	return (str);
}

void	start(char *args)
{
	t_node	*a;
	t_node	*b;
	t_node	*tmpa;

	a = NULL;
	b = NULL;
	tmpa = NULL;
	ft_check_error_con(args);
	ft_init_s(&a, args);
	start_sort(&a, &b, &tmpa);
}

int	main(int argc, char **argv)
{
	char	*args;
	int		i;
	int		j;
	bool	flag;

	if (argc < 2)
		return (0);
	i = 1;
	j = 0;
	args = "";
	flag = false;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ' && argv[i][j])
		{
			j++;
			if (argv[i][j] == '\0')
			{
				write(2, "Errorrrr\n", 10);
				return(1);
			}
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		args = ft_strjoin(args, " ", flag);
		flag = true;
		args = ft_strjoin(args, argv[i], flag);
		i++;
	}
	start(args);
	free(args);
	return (0);
}
