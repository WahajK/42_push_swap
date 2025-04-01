/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:59:20 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:00:59 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*b_iterator;
	t_node	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		b_iterator = b;
		while (b_iterator)
		{
			if (b_iterator->data < a->data
				&& b_iterator->data > best_match)
			{
				best_match = b_iterator->data;
				target = b_iterator;
			}
			b_iterator = b_iterator->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	calculate_cost_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_node *head)
{
	long	cheapest_val;
	t_node	*cheapest_node;

	if (!head)
		return ;
	cheapest_val = LONG_MAX;
	while (head)
	{
		if (head->push_cost < cheapest_val)
		{
			cheapest_val = head->push_cost;
			cheapest_node = head;
		}
		head = head->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_list **a, t_list **b)
{
	set_index_median((*a)->head);
	set_index_median((*b)->head);
	set_target_a((*a)->head, (*b)->head);
	calculate_cost_a((*a)->head, (*b)->head);
	set_cheapest((*a)->head);
}

t_node	*get_cheapest(t_node *head)
{
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}
