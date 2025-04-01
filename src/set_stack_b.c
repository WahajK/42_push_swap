/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:01:39 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:10:04 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rr_both(t_list **a, t_list **b, t_node *cheapest)
{
	while ((*b)->head != cheapest->target_node && (*a)->head != cheapest)
		rrr(a, b);
	set_index_median((*a)->head);
	set_index_median((*b)->head);
}

void	move_a_to_b(t_list **a, t_list **b)
{
	t_node	*cheapest;

	cheapest = get_cheapest((*a)->head);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rr_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		rev_rr_both(a, b, cheapest);
	target_to_top(a, cheapest, 'a');
	target_to_top(b, cheapest->target_node, 'b');
	px(b, a, 'b');
}

t_node	*find_min(t_node *head)
{
	t_node	*min;

	if (!head)
		return (NULL);
	min = head;
	while (head)
	{
		if (head->data < min->data)
			min = head;
		head = head->next;
	}
	return (min);
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*a_iterator;
	t_node	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		a_iterator = a;
		while (a_iterator)
		{
			if (a_iterator->data > b->data
				&& a_iterator->data < best_match)
			{
				best_match = a_iterator->data;
				target = a_iterator;
			}
			a_iterator = a_iterator->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_nodes_b(t_list **a, t_list **b)
{
	set_index_median((*a)->head);
	set_index_median((*b)->head);
	set_target_b((*a)->head, (*b)->head);
}
