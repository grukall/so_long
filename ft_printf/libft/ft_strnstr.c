/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:53:25 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:02:40 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_dest_src(const char *dest, const char *src, size_t len)
{
	const char	*temp;
	int			i;

	i = 0;
	while (len != 0 && *dest)
	{
		if (*dest == *src)
		{
			i = 0;
			temp = dest;
			while (*(src + i) != '\0' && (size_t)i < len)
			{
				if (*(src + i) != *(dest + i))
					break ;
				i++;
			}
			if (*(src + i) == '\0')
				return ((char *)temp);
		}
		len--;
		dest++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	if (*src == '\0')
		return ((char *)dest);
	return (check_dest_src(dest, src, len));
}
