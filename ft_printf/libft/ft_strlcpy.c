/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:23:22 by seungule          #+#    #+#             */
/*   Updated: 2023/03/31 19:21:33 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wr(char *dest, const char *src, size_t size, size_t len)
{
	size_t	i;

	i = 0;
	if (size <= len)
	{
		while (i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	else if (size > len)
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

size_t	ft_strlcpy(char *dest, const char *src,	size_t size)
{
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size)
		wr(dest, src, size, len);
	return (len);
}
