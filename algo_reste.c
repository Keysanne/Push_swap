/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_reste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:23:53 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/10 13:28:03 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	near_reste(t_list **b, int x)
{
	int		taille;
	int		i;
	t_list	*swp;

	i = 0;
	swp = *b;
	while (swp->data != x)
	{
		i++;
		swp = swp->next;
	}
	swp = *b;
	taille = lst_size(*b);
	if (i < taille / 2)
		rb(b);
	else
		rrb(b);
}

void	algo_reste(t_list **a, t_list **b, int taille)
{
	int	x;

	while (lst_size(*b) < taille)
	{
		pb(a, b);
	}
	x = taille;
	while (x > 0)
	{
		while ((*b)->data != x)
		{
			near_reste(b, x);
		}
		if ((*b)->data == x)
			pa(a, b);
		x--;
	}
}
