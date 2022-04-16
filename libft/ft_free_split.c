#include "libft.h"

void	ft_free_split(char **split_result)
{
	int	i;

	if (split_result)
	{
		i = 0;
		while (split_result[i])
		{
			free(split_result[i]);
			split_result[i] = NULL;
			i++;
		}
		free(split_result);
		split_result = NULL;
	}
}
