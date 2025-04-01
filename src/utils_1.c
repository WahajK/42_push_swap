/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1..c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:54:52 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:09:58 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
