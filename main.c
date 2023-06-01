/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:56:25 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/30 18:45:44 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*tab_to_list(t_list *pile, t_list *stock, char **argv, int argc)
{
	int		x;
	t_list	*swp;

	pile->data = ft_atol(argv[1]);
	pile->next = NULL;
	swp = pile;
	x = 2;
	while (x < argc)
	{
		stock = malloc(sizeof(t_list));
		if (!stock)
			exit (0);
		stock->data = ft_atol(argv[x]);
		stock->next = NULL;
		pile->next = stock;
		pile = pile->next;
		x++;
	}
	return (swp);
}

void	print_list(t_list *pile)
{
	while (pile)
	{
		printf("%ld\n", pile->data);
		pile = pile->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	stock;

	if (argc == 1)
		write(1, "error\n", 6);
	else
	{
		verif(argv, argc);
		a = malloc(sizeof(t_list));
		if (!a)
			return (-1);
		b = NULL;
		a = tab_to_list(a, &stock, argv, argc);
		print_list(a);
		print_list(b);
		free_list(a);
	}
	return (0);
}
