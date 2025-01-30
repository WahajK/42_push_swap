/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:27:39 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:08:37 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putstr_fd - Outputs the string 's' to the given file descriptor 'fd'.
 * @s: The string to output.
 * @fd: The file descriptor on which to write.
 *
 * This function writes the string 's' to the file descriptor 'fd'. If 's' is
 * NULL, the function does nothing.
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
