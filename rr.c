/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:53:21 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/01 17:14:43 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **pile)
{
	t_list	*swp;
	t_list	*cell;

	swp = *pile;
	cell = (*pile)->next;
	while (cell->next)
	{
		cell = cell->next;
		swp = swp->next;
	}
	swp->next = NULL;
	cell->next = *pile;
	*pile = cell;
}

void	rr2(t_list **pile, t_list **stock)
{
	rr(pile);
	rr(stock);
}
