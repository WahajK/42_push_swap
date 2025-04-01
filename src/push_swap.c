/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:13:17 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:29:06 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
