/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:13:17 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/31 19:36:03 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"

int	ft_nan(char *num)
{
	if (*num == '-' || *num == '+')
		num++;
	if (!*num)
		return (1);
	while (*num)
		if (!ft_isdigit(*num++))
			return (1);
	return (0);
}

int	check_error(char *arr[])
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_nan(arr[i]))
			return (1);
		i++;
	}
	return (0);
}

void	destructor(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**parse_input(int argc, char *argv[])
{
	int		i;
	char	**arr;

	arr = malloc((argc) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = ft_strdup(argv[i]);
		if (!arr[i - 1])
		{
			destructor(arr);
			return (NULL);
		}
		i++;
	}
	arr[argc - 1] = NULL;
	return (arr);
}

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

int	check_dupes(t_list **a, char **arr)
{
	int		i;
	long	num;
	t_node	*temp;

	i = 0;
	while (arr[i])
	{
		num = ft_atol(arr[i], &i);
		if (i == -1)
			return (free_stack(a), 1);
		temp = (*a)->head;
		while (temp)
		{
			if (num > INT_MAX || num < INT_MIN || temp->data == num)
			{
				return (free_stack(a), 1);
			}
			temp = temp->next;
		}
		ft_lstadd_back(&((*a)->head), &((*a)->tail), ft_lstnew(num));
		i++;
	}
	return (0);
}

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

void	sort_three(t_list **a)
{
	t_node	*max;

	max = find_max((*a)->head);
	if (!max)
		return ;
	if (max == (*a)->head)
		rx(a, 'a', true);
	else if ((*a)->head->next == max)
		rrx(a, 'a', true);
	if ((*a)->head->data > (*a)->head->next->data)
		sx(&((*a)->head), 'a', true);
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

void	rr_both(t_list **a, t_list **b, t_node *cheapest)
{
	while ((*b)->head != cheapest->target_node && (*a)->head != cheapest)
		rr(a, b);
	set_index_median((*a)->head);
	set_index_median((*b)->head);
}

void	rev_rr_both(t_list **a, t_list **b, t_node *cheapest)
{
	while ((*b)->head != cheapest->target_node && (*a)->head != cheapest)
		rrr(a, b);
	set_index_median((*a)->head);
	set_index_median((*b)->head);
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

void	turk_sort(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize((*a)->head);
	if (len-- > 3 && !is_sorted(a))
		px(b, a, 'b');
	if (len-- > 3 && !is_sorted(a))
		px(b, a, 'b');
	while (len-- > 3 && !is_sorted(a))
	{
		init_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while ((*b)->head)
	{
		init_nodes_b(a, b);
		move_b_to_a(a, b);
	}
	set_index_median((*a)->head);
	min_to_top(a);
}

int	push_swap(char **arr)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstinit();
	b = ft_lstinit();
	if (!a || check_dupes(&a, arr))
		return (free_stack(&b), 1);
	if (!b)
	{
		free_stack(&a);
		return (1);
	}
	if (!is_sorted(&a))
	{
		if (ft_lstsize(a->head) == 2)
			sx(&(a->head), 'a', true);
		else if (ft_lstsize(a->head) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**arr;

	arr = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr || check_error(arr))
			return (ft_printf("Error\n"), destructor(arr), 1);
		if (push_swap(arr))
			return (ft_printf("Error\n"), destructor(arr), 1);
		destructor(arr);
		return (0);
	}
	arr = parse_input(argc, argv);
	if (!arr)
		return (1);
	if (check_error(arr))
		return (ft_printf("Error\n"), destructor(arr), 1);
	if (push_swap(arr))
		return (ft_printf("Error\n"), destructor(arr), 1);
	destructor(arr);
	return (0);
}
