/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:22:25 by seungule          #+#    #+#             */
/*   Updated: 2023/03/31 19:25:42 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	dest_size = ft_strlen((const char *)dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size <= dest_size)
		return (size + src_size);
	else
	{
		while (src[i] && (i < size - dest_size - 1))
		{
			dest[dest_size + i] = src[i];
			i++;
		}
		dest[dest_size + i] = '\0';
		return (dest_size + src_size);
	}
}
