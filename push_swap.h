/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:00:29 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/30 13:04:18 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	long int	data;
	void		*next;
}		t_list;

t_list		*lst_last(t_list *a);
long int	ft_atol(char *nptr);
int			trier(t_list *a);
int			lst_size(t_list *b);
void		free_list(t_list *pile);
void		verif(char **argv, int argc);
void		sa(t_list **pile);
void		sb(t_list **pile);
void		ss(t_list **pile, t_list **stock);
void		pa(t_list **stock, t_list **pile);
void		pb(t_list **pile, t_list **stock);
void		ra(t_list **pile);
void		rb(t_list **pile);
void		rr(t_list **pile, t_list **stock);
void		rra(t_list **pile);
void		rrb(t_list **pile);
void		rrr(t_list **pile, t_list **stock);
void		algorithme(t_list **a, t_list **b, int taille);
void		algo_3(t_list **a);
void		algo_6(t_list **a, t_list **b);
void		algo_2(t_list **a);
void		algo_100(t_list **a, t_list **b);
void		algo_500(t_list **a, t_list **b);
void		algo_reste(t_list **a, t_list **b, int taille);
char		*ft_itoa(int n);

#endif
