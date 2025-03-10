/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:13:17 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/10 17:36:58 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "limits.h"

int	ft_NaN(char *num)
{
	if (*num == '-')
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
		if (ft_NaN(arr[i]))
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
			return (printf("Error\n"), 1);
		destructor(arr);
	}
	return (0);
}