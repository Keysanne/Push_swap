/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:55:40 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/05 16:14:40 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	trier(t_list *a)
{
	t_list		*test;
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

void	algorithme(t_list **a, t_list **b, int taille)
{
	if (trier(*a) == 0)
		return ;
	if (taille == 2)
		algo_2(a);
	else if (taille == 3)
		algo_3(a);
	else if (taille <= 6)
		algo_6(a, b);
	else if (taille == 100)
		algo_100(a, b);
	else if (taille == 500)
		algo_500(a, b);
	else
		algo_reste(a, b, taille);
}
