/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_and_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:56:21 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/01 16:53:09 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list **pile)
{
	t_list	*swp;

	swp = (*pile)->next;
	(*pile)->next = swp->next;
	swp->next = *pile;
	*pile = swp;
}

void	s2(t_list **pile, t_list **stock)
{
	s(pile);
	s(stock);
}

void	p(t_list **pile, t_list **stock)
{
	t_list	*swp;

	swp = (*pile);
	(*pile) = (*pile)->next;
	swp->next = (*stock);
	*stock = swp;
}

void	r(t_list **pile)
{
	t_list	*swp;
	t_list	*cell;

	swp = *pile;
	cell = *pile;
	*pile = (*pile)->next;
	while (swp->next)
		swp = swp->next;
	swp->next = cell;
	cell->next = NULL;
}

void	r2(t_list **pile, t_list **stock)
{
	r(pile);
	r(stock);
}
