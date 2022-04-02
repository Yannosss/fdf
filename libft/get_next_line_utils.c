/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:46:46 by ybellot           #+#    #+#             */
/*   Updated: 2022/01/06 11:46:50 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_initbuffer(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
	return (buf);
}

int	ft_has_eol(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_buflen(char *str)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (i < BUFFER_SIZE && str[i] != 0 && str[i] != '\n')
	{
		size++;
		str++;
		i++;
	}
	if (str[i] == '\n')
		size++;
	return (size);
}
