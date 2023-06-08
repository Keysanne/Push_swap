/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:43:32 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/08 15:59:57 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	premier_tri(t_list **a, t_list **b, int x)
{
	t_list	*second;
	t_list	*last;

	x *= 20;
	while (lst_size(*b) != x - 1 && (*a)->next)
	{
		second = (*a)->next;
		last = lst_last(*a);
		if ((*a)->data < x)
			pb(a, b);
		else if (last->data < x)
		{
			rra(a);
			pb(a, b);
		}
		else if (second->data < x)
		{
			ra(a);
			pb(a, b);
		}
		else
			ra(a);
	}
}

void	renvois(t_list **a, t_list **b, int x)
{
	t_list	*second;
	t_list	*last;

	while (lst_size(*a) < 20 * x && (*b)->next)
	{
		second = (*b)->next;
		last = lst_last(*b);
		if ((*b)->data == (*a)->data - 1)
			pa(a, b);
		else if (last->data == (*a)->data - 1)
		{
			rrb(b);
			pa(a, b);
		}
		else if (second->data == (*a)->data - 1)
		{
			sb(b);
			pa(a, b);
		}
		else
			rb(b);
	}
}

void	algo_100(t_list **a, t_list **b)
{
	int	x;

	x = 1;
	if (trier(*a) == 1)
	{
		while (x <= 5 && (*a)->next)
		{
			premier_tri(a, b, x);
			x++;
		}
		x = 1;
		while (x <= 5)
		{
			renvois(a, b, x);
			x++;
		}
	}
	pa(a, b);
}
