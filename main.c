/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:56:25 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/02 16:00:40 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_last(t_list *a)
{
	t_list	*swp;

	swp = a;
	while (swp->next)
		swp = swp->next;
	return (swp);
}

t_list	*tab_to_list(t_list *pile, t_list *stock, char **argv, int argc)
{
	int		x;
	t_list	*swp;

	pile->data = ft_atol(argv[1]) + 2147483649;
	pile->next = NULL;
	swp = pile;
	x = 2;
	while (x < argc)
	{
		stock = malloc(sizeof(t_list));
		if (!stock)
			exit (0);
		stock->data = ft_atol(argv[x]) + 2147483649;
		stock->next = NULL;
		pile->next = stock;
		pile = pile->next;
		x++;
	}
	return (swp);
}

void	simplifier(char **argv)
{
	int	x;
	int	j;
	int	v;

	v = -2147483648;
	while (v <= -2147383648)
	{
		j = 1;
		x = j;
		while (argv[j])
		{
			while (argv[x + 1] && ft_atol(argv[x]) < v)
				x++;
			if (ft_atol(argv[j]) < ft_atol(argv[x]) && ft_atol(argv[j]) > v)
				x = j;
			j++;
		}
		if (ft_atol(argv[x]) > v)
			argv[x] = ft_itoa(v);
		v++;
	}
}

void	print_list(t_list *pile)
{
	printf("-----------------------\n");
	while (pile)
	{
		printf("%ld\n", pile->data);
		pile = pile->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	stock;

	if (argc == 1)
		return (0);
	else
	{
		verif(argv, argc);
		simplifier(argv);
		a = malloc(sizeof(t_list));
		if (!a)
			return (-1);
		b = NULL;
		a = tab_to_list(a, &stock, argv, argc);
		algorithme(&a, &b, argc - 1);
		print_list(a);
		print_list(b);
		free_list(a);
	}
	return (0);
}
