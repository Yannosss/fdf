/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:02 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:00:10 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t			i;
	unsigned char	*pt1;
	unsigned char	*pt2;

	if (size == 0)
		return (0);
	pt1 = (unsigned char *)pointer1;
	pt2 = (unsigned char *)pointer2;
	i = 0;
	while (i < size - 1 && (*(pt1 + i) == *(pt2 + i)))
	{
		i++;
	}
	return (*(pt1 + i) - *(pt2 + i));
}
