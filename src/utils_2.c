/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:56:56 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:10:12 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_list **a)
{
	t_node	*temp;

	temp = (*a)->head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	free_stack(t_list **a)
{
	ft_lstclear(&((*a)->head), &((*a)->tail));
	free(*a);
}

t_node	*find_max(t_node *head)
{
	t_node	*max;

	if (!head)
		return (NULL);
	max = head;
	while (head)
	{
		if (head->data > max->data)
			max = head;
		head = head->next;
	}
	return (max);
}

void	set_index_median(t_node *head)
{
	int	i;
	int	median;

	if (!head)
		return ;
	i = 0;
	median = ft_lstsize(head) / 2;
	while (head)
	{
		head->index = i;
		if (i <= median)
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
		i++;
	}
}

void	rr_both(t_list **a, t_list **b, t_node *cheapest)
{
	while ((*b)->head != cheapest->target_node && (*a)->head != cheapest)
		rr(a, b);
	set_index_median((*a)->head);
	set_index_median((*b)->head);
}
