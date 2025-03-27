/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:13:17 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/27 22:48:07 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "limits.h"
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

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

char	**parse_input(int argc, char *argv[])
{
	int		i;
	char	**arr;

	i = 0;
	arr = malloc (argc * sizeof(char *));
	while (argv[i])
	{
		arr[i] = ft_strdup(argv[i]);
		i++;
	}
	return (arr);
}
// WIP
int	check_dupes(char **arr)
{
	t_node	*temp;
	t_list	*list;
	int	i;

	i = 0;
	list = ft_lstinit();
	if (!list)
		return (1);
	while (arr[i])
	{
		temp = list->head;
		while (temp)
		{
			printf("%d %s\n", temp->data, arr[i]);
			if (ft_strcmp(ft_itoa(temp->data), arr[i]) == 0)
				return (1);
			temp = temp->next;
		}
		ft_lstadd_back(&(list->head), &(list->tail), ft_lstnew(ft_atoi(arr[i])));
		i++;
	}
	// ft_lstclear(&seen, free);
	return (0);
}

void	sx(t_node *a)
{
	int	temp;
	if (a && a->next)
	{
		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
	}
}

void	ss(t_node *a, t_node *b)
{
	sx(a);
	sx(b);
}

// void	pa(t_node *a, t_node *b)
// {
// 	ft_lstadd_front(&a, b);
// 	ft_lstdelone
// }
int	main(int argc, char *argv[])
{
	char	**arr;

	arr = NULL;
	if (argc < 2 || !argv[1][0])
		return (-1);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (check_error(arr))
			return (ft_printf("Error\n"), destructor(arr), 1);
	}
	else
	{
		arr = parse_input(argc, argv + 1);
		if (check_error(argv + 1))
			return (ft_printf("Error\n"), destructor(arr), 1);
	}
	if (check_dupes(arr))
		return (ft_printf("Error\n"), destructor(arr), 1);
	
	destructor(arr);
	return (0);
}
