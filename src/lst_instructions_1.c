/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_instructions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:47:24 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:09:35 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sx(t_node **a, char ch, bool flag)
{
	int	temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	if (flag)
	{
		if (ch == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	ss(t_node **a, t_node **b)
{
	sx(a, 'a', false);
	sx(b, 'b', false);
	ft_printf("ss\n");
}

void	px(t_list **x, t_list **swap, char ch)
{
	t_node	*temp;

	if (!(*swap) || !(*swap)->head)
		return ;
	temp = (*swap)->head;
	if (!(*swap)->head->next)
	{
		(*swap)->head = NULL;
		(*swap)->tail = NULL;
	}
	else
	{
		(*swap)->head = (*swap)->head->next;
		(*swap)->head->prev = NULL;
	}
	temp->next = (*x)->head;
	if ((*x)->head)
		(*x)->head->prev = temp;
	else
		(*x)->tail = temp;
	(*x)->head = temp;
	if (ch == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rx(t_list **x, char ch, bool flag)
{
	t_node	*temp;

	if (!x || !*x || !(*x)->head || !(*x)->head->next)
		return ;
	temp = (*x)->head;
	(*x)->head = (*x)->head->next;
	(*x)->head->prev = NULL;
	temp->next = NULL;
	(*x)->tail->next = temp;
	temp->prev = (*x)->tail;
	(*x)->tail = temp;
	if (flag)
	{
		if (ch == 'a')
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	rr(t_list **a, t_list **b)
{
	rx(a, 'a', false);
	rx(b, 'b', false);
	ft_printf("rr\n");
}
