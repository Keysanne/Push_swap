/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:33:06 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/09 15:55:15 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	premier_tri_500(t_list **a, t_list **b, int x)
{
	t_list	*second;
	t_list	*last;

	x *= 50;
	while (lst_size(*b) != 50)
	{
		second = (*a)->next;
		last = lst_last(*a);
		if ((*a)->data <= x && (*a)->data > x - 50)
			pb(a, b);
		else if (last->data <= x && last->data > x - 50)
		{
			rra(a);
			pb(a, b);
		}
		else if (second->data <= x && second->data > x - 50)
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

void	near_500(t_list **a, t_list **b)
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

void	renvois_500(t_list **a, t_list **b)
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
			near_500(a, b);
	}
}

void	algo_500(t_list **a, t_list **b)
{
	int		x;
	t_list	*last;

	x = 1;
	if (trier(*a) == 1)
	{
		while (x <= 10 && (*a)->next)
		{
			premier_tri_500(a, b, x);
			pa(a, b);
			pa(a, b);
			ra(a);
			renvois_500(a, b);
			x++;
		}
		last = lst_last(*a);
		while ((*a)->data > last->data)
			ra(a);
	}
}
