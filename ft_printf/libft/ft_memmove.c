/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:41:01 by seungule          #+#    #+#             */
/*   Updated: 2023/03/19 14:52:33 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t		i;

	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		while (num)
		{
			((char *)dest)[num - 1] = ((const char *)src)[num - 1];
			num--;
		}
	}
	else
	{
		i = 0;
		while (i < num)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dest);
}
