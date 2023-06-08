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

void	sa(t_list **pile)
{
	t_list	*swp;

	swp = (*pile)->next;
	(*pile)->next = swp->next;
	swp->next = *pile;
	*pile = swp;
	write(1, "sa\n", 3);
}

void	sb(t_list **pile)
{
	t_list	*swp;

	swp = (*pile)->next;
	(*pile)->next = swp->next;
	swp->next = *pile;
	*pile = swp;
	write(1, "sb\n", 3);
}

void	ss(t_list **pile, t_list **stock)
{
	sa(pile);
	sb(stock);
}

void	pb(t_list **pile, t_list **stock)
{
	t_list	*swp;

	swp = (*pile);
	(*pile) = (*pile)->next;
	swp->next = (*stock);
	*stock = swp;
	write(1, "pb\n", 3);
}

void	pa(t_list **stock, t_list **pile)
{
	t_list	*swp;

	swp = (*pile);
	(*pile) = (*pile)->next;
	swp->next = (*stock);
	*stock = swp;
	write(1, "pa\n", 3);
}
