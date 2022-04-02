/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:40 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:02:29 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedchar)
{
	char	*str;

	str = (char *)string;
	while (*str)
	{
		if ((char)searchedchar == *str)
			return ((char *)str);
		str++;
	}
	if (searchedchar == 0)
		return (str);
	return (NULL);
}
