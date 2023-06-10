/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:43:32 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/10 14:39:49 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	premier_tri(t_list **a, t_list **b, int x)
{
	t_list	*second;
	t_list	*last;

	x *= 25;
	while (lst_size(*b) != 25)
	{
		second = (*a)->next;
		last = lst_last(*a);
		if ((*a)->data <= x && (*a)->data > x - 25)
			pb(a, b);
		else if (last->data <= x && last->data > x - 25)
		{
			rra(a);
			pb(a, b);
		}
		else if (second->data <= x && second->data > x - 25)
		{
			ra(a);
			pb(a, b);
		}
		else
			rra(a);
	}
	while ((*b)->data != x)
		rb(b);
}

void	near_100(t_list **a, t_list **b)
{
	int		taille;
	int		i;
	t_list	*swp;

	i = 0;
	swp = *b;
	while (swp->data != (*a)->data - 1)
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

void	renvois(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	while ((*b))
	{
		second = (*b)->next;
		last = lst_last(*a);
		if ((*b)->data == (*a)->data - 1)
			pa(a, b);
		else if (last->data == (*a)->data - 1)
			rra(a);
		else if ((*b)->data == last->data + 1)
		{
			pa(a, b);
			ra(a);
		}
		else if (second->data == (*a)->data - 1)
		{
			sb(b);
			pa(a, b);
		}
		else
			near_100(a, b);
	}
}

void	algo_100(t_list **a, t_list **b)
{
	int		x;
	t_list	*last;

	x = 1;
	if (trier(*a) == 1)
	{
		while (x <= 4 && (*a)->next)
		{
			premier_tri(a, b, x);
			pa(a, b);
			pa(a, b);
			ra(a);
			renvois(a, b);
			x++;
		}
		last = lst_last(*a);
		while ((*a)->data > last->data)
			ra(a);
	}
}
