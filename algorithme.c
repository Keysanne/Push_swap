/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:55:40 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/02 15:08:03 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	trier(t_list *a)
{
	t_list	*test;
	long int	valeur;

	test = a;
	while (test->next)
	{
		valeur = test->data;
		test = test->next;
		if (valeur > test->data)
			return (1);
	}
	return (0);
}

void	algorithme(t_list **a, t_list **b)
{
	printf ("%d\n\n", trier(*a));
	if (!(*b))
		return ;
}
