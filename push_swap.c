/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:13:17 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/30 01:55:57 by muhakhan         ###   ########.fr       */
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

void	sx(t_node **a)
{
	int	temp;

	if (!a || !(*a)->next)
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
}

void	ss(t_node **a, t_node **b)
{
	sx(a);
	sx(b);
}

void	px(t_list **x, t_list **swap)
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
}

void	rx(t_list **x)
{
	t_node	*temp;

	if (!x || !(*x)->head || !(*x)->head->next)
		return ;
	temp = (*x)->head;
	(*x)->head = (*x)->head->next;
	(*x)->head->prev = NULL;
	temp->next = NULL;
	(*x)->tail->next = temp;
	temp->prev = (*x)->tail;
	(*x)->tail = temp;
}

void	rr(t_list **a, t_list **b)
{
	rx(a);
	rx(b);
}

void	rrx(t_list **x)
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
}

void	rrr(t_list **a, t_list **b)
{
	rrx(a);
	rrx(b);
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
			return (1);
		temp = temp->next;
	}
	return (0);
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
		rx(a);
	else if ((*a)->head->next == max)
		rrx(a);
	if ((*a)->head->data > (*a)->head->next->data)
		sx(&((*a)->head));
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
			head->above_median = false;
		else
			head->above_median = true;
		head = head->next;
		i++;
	}
}

void	set_target(t_node *a, t_node *b)
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

void	init_nodes_a(t_list **a, t_list **b)
{
	set_index_median((*a)->head);
	set_index_median((*b)->head);
	set_target_a((*a)->head, (*b)->head);
	calculate_cost_a(a, b);
	set_cheapest(a);
}

void	turk_sort(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize((*a)->head);
	if (len-- > 3 && !is_sorted(a));
		px(b, a);
	if (len-- > 3 && !is_sorted(a));
		px(b, a);
	while (len-- > 3 && !is_sorted(a))
	{
		init_nodes_a(a, b);
	}
	
}

int	push_swap(char **arr)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstinit();
	b = ft_lstinit();
	if (!a)
		return (1);
	if (check_dupes(&a, arr))
		return (1);
	if (!is_sorted(&a))
	{
		if (ft_lstsize(a->head) == 2)
			sx(&(a->head));
		else if (ft_lstsize(a->head) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	if (is_sorted(&a))
		ft_printf("SORTED!");
	free_stack(&a);
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
