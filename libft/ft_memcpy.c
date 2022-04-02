/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:05 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:00:37 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;

	if (source == destination)
		return (destination);
	i = 0;
	while (i < size)
	{
		((char *)destination)[i] = ((char *)source)[i];
		i++;
	}
	return (destination);
}
