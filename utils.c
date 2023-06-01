/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:06:20 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/01 17:43:30 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(char *nptr)
{
	long int	rst;
	int			i;
	int			cpt;

	i = 0;
	rst = 0;
	cpt = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			cpt = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		rst = rst * 10 + (nptr[i++] - '0');
	if (cpt == 1)
		rst = -rst;
	return (rst);
}

void	free_list(t_list *pile)
{
	t_list	*tmp;

	tmp = pile;
	while (pile)
	{
		tmp = pile->next;
		free(pile);
		pile = tmp;
	}
}

void	doublon(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
			{
				write(1, "error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	verif(char **argv, int argc)
{
	int	i;
	int	j;

	j = 1;
	doublon(argv, argc);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] != '-' && argv[j][i] != '+'
				&& !(argv[j][i] >= '0' && argv[j][i] <= '9'))
			{
				write(1, "error\n", 6);
				exit (0);
			}
			i++;
		}
		if (ft_atol(argv[j]) > 2147483647 || ft_atol(argv[j]) < -2147483648)
		{
			write(1, "error\n", 6);
			exit (0);
		}
		j++;
	}	
}
