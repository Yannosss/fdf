/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:09 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:00:58 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	if (source >= destination)
	{
		ft_memcpy(destination, source, size);
	}
	else
	{
		while (size)
		{
			((char *)destination)[size - 1] = ((char *)source)[size - 1];
			size--;
		}
	}
	return (destination);
}
