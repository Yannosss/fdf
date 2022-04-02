/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:07 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:03:51 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	if (length == 0)
		return (0);
	while (*s1 && length - 1)
	{
		if (*s1 != *s2)
			return ((int)((*(unsigned char *)s1 - *(unsigned char *)s2)));
		s1++;
		s2++;
		length--;
	}
	return ((int)((*(unsigned char *)s1 - *(unsigned char *)s2)));
}
