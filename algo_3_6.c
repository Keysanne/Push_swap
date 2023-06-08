/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:11:17 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/05 16:53:43 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tas_de_3(t_list **a, t_list **b)
{
	t_list	*last;

	while (trier(*a) == 1 || (*b))
	{
		last = lst_last(*a);
		if (last->data < 4)
			rra(a);
		if ((*a)->data < 4)
			pb(a, b);
		else
			ra(a);
		if (lst_size(*b) == 3)
			break ;
	}
}

void	reverse_algo_3(t_list *b)
{
	t_list	*last;
	t_list	*mid;

	mid = b->next;
	last = b;
	while (last->next)
		last = last->next;
	if (b->data > last->data && last->data > mid->data)
		write(1, "rrb\nsb\n", 7);
	else if (mid->data > last->data && last->data > b->data)
		write(1, "rb\n", 3);
	else if (mid->data > b->data && b->data > last->data)
		write(1, "sb\n", 3);
	else if (last->data > mid->data && mid->data > b->data)
		write(1, "sb\nrrb\n", 7);
	else if (last->data > b->data && b->data > mid->data)
		write(1, "rrb\n", 4);
}

void	cas_particulier(t_list *a, t_list *b)
{
	t_list	*last_a;
	t_list	*last_b;
	t_list	*mid_a;
	t_list	*mid_b;

	mid_a = a->next;
	mid_b = b->next;
	last_a = a;
	last_b = b;
	while (last_a->next)
		last_a = last_a->next;
	while (last_b->next)
		last_b = last_b->next;
	if ((b->data > last_b->data && last_b->data > mid_b->data)
		|| (last_b->data > mid_b->data && mid_b->data > b->data))
	{
		if ((a->data > mid_a->data && mid_a->data > last_a->data)
			|| (mid_a->data > last_a->data && last_a->data > a->data))
		{
			write(1, "rrr\nss\npa\npa\npa\n", 16);
			free_list(a);
			free_list(b);
			exit (0);
		}
	}
}

void	algo_6(t_list **a, t_list **b)
{
	tas_de_3(a, b);
	if (trier(*a) == 0 && !(*b))
		return ;
	if ((*a)->next)
		cas_particulier(*a, *b);
	if ((*a)->next)
		algo_3(a);
	reverse_algo_3(*b);
	write(1, "pa\npa\npa\n", 9);
}

void	algo_3(t_list **a)
{
	t_list	*last;
	t_list	*mid;

	mid = (*a)->next;
	if (lst_size(*a) == 2 && (*a)->data > mid->data)
		write(1, "sa\n", 3);
	last = *a;
	while (last->next)
		last = last->next;
	if ((*a)->data > mid->data && mid->data > last->data)
		write(1, "sa\nrra\n", 7);
	else if (mid->data > last->data && last->data > (*a)->data)
		write(1, "rra\nsa\n", 7);
	else if (last->data > (*a)->data && (*a)->data > mid->data)
		write(1, "sa\n", 3);
	else if (mid->data > (*a)->data && (*a)->data > last->data)
		write(1, "rra\n", 4);
	else if ((*a)->data > last->data && last->data > mid->data)
		write(1, "ra\n", 3);
}
