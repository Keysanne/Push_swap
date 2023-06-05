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
void		s(t_list **pile);
void		s2(t_list **pile, t_list **stock);
void		p(t_list **pile, t_list **stock);
void		r(t_list **pile);
void		r2(t_list **pile, t_list **stock);
void		rr(t_list **pile);
void		rr2(t_list **pile, t_list **stock);
void		algorithme(t_list **a, t_list **b, int taille);
void		algo_3(t_list **a);
void		algo_6(t_list **a, t_list **b);
char		*ft_itoa(int n);

#endif
