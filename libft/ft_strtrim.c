/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:50:09 by esouza            #+#    #+#             */
/*   Updated: 2017/12/05 02:59:45 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	size_t	n;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	n = ft_strlen(s);
	while (n > 0 && ft_iswhitespace(s[n - 1]))
		n--;
	return (ft_strsub(s, 0, n));
}
