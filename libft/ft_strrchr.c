/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:14 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:04:14 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedchar)
{
	char	*last_found;

	last_found = NULL;
	while (*string)
	{
		if (*string == (char)searchedchar)
			last_found = (char *)string;
		string++;
	}
	if (searchedchar == 0)
		last_found = (char *)string;
	return (last_found);
}
