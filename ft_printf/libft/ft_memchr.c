/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:38:06 by seungule          #+#    #+#             */
/*   Updated: 2023/03/19 18:23:45 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	char	*ch;

	ch = (char *)buf;
	if (count == 0)
		return (NULL);
	while (count != 0)
	{
		if (*ch == (char)c)
			return ((void *)ch);
		ch++;
		count--;
	}
	return (NULL);
}
