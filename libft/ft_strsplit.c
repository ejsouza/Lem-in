/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:09:28 by esouza            #+#    #+#             */
/*   Updated: 2017/12/02 19:41:23 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	int				i;
	int				wlen;
	int				index;
	char			**array;

	if (s)
	{
		i = 0;
		wlen = ft_wordcount((char *)s, c);
		index = 0;
		if (!(array = (char **)malloc((wlen + 1) * sizeof(char **))))
			return (NULL);
		while (index < ft_wordcount((char *)s, c))
		{
			while (s[i] == c)
				i++;
			array[index] = ft_strsub(s, i, ft_wordlen(&s[i], c));
			i += ft_wordlen(&s[i], c);
			index++;
		}
		array[index] = 0;
		return (array);
	}
	return (NULL);
}
