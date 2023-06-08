/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:38:05 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/08 13:38:23 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **pile)
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
	write(1, "ra\n", 3);
}

void	rb(t_list **pile)
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
	write(1, "rb\n", 3);
}

void	rr(t_list **pile, t_list **stock)
{
	ra(pile);
	rb(stock);
}
