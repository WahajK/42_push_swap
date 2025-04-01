/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_instructions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:51:39 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:03:08 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrx(t_list **x, char ch, bool flag)
{
	t_node	*temp;

	if (!(*x) || !(*x)->tail || !(*x)->tail->prev)
		return ;
	temp = (*x)->tail;
	(*x)->tail = (*x)->tail->prev;
	(*x)->tail->next = NULL;
	temp->prev = NULL;
	temp->next = (*x)->head;
	(*x)->head->prev = temp;
	(*x)->head = temp;
	if (flag)
	{
		if (ch == 'a')
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

void	rrr(t_list **a, t_list **b)
{
	rrx(a, 'a', false);
	rrx(b, 'b', false);
	ft_printf("rrr\n");
}

void	target_to_top(t_list **a, t_node *target, char stack)
{
	while ((*a)->head != target)
	{
		if (target->above_median)
			rx(a, stack, true);
		else
			rrx(a, stack, true);
	}
}

void	move_b_to_a(t_list **a, t_list **b)
{
	target_to_top(a, (*b)->head->target_node, 'a');
	px(a, b, 'a');
}

void	min_to_top(t_list **a)
{
	while ((*a)->head->data != find_min((*a)->head)->data)
	{
		if (find_min((*a)->head)->above_median)
			rx(a, 'a', true);
		else
			rrx(a, 'a', true);
	}
}
