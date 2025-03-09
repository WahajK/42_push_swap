/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:13:17 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/09 22:48:48 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "limits.h"
int	check_error(char *arr[])
{
	int	**vals;
	int	i;
	int	*hash_table;

	i = 0;
	hash_table = malloc(INT_MAX * sizeof(int));
	while (arr[i])
	{
		if (!hash_table[ft_atoi(arr[i])])
			hash_table[ft_atoi(arr[i])] = 1;
		else
			return (1);
		i++;
	}
	return (0);
}
int	main(int argc, char *argv[])
{
	int	i;
	char	**arr;

	arr = NULL;
	if (argc < 2 || !argv[1][0])
		return (-1);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (check_error(arr))
			return (printf("Error\n"), 1);
		// push_swap(arr);
		// free_arr(arr);
	}
	return (0);
}