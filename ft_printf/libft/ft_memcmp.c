/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:04:22 by seungule          #+#    #+#             */
/*   Updated: 2023/03/19 18:53:04 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*tempbuf1;
	unsigned char	*tempbuf2;

	tempbuf1 = (unsigned char *)buf1;
	tempbuf2 = (unsigned char *)buf2;
	while (count != 0)
	{
		if (*tempbuf1 != *tempbuf2)
			return ((int)(*tempbuf1 - *tempbuf2));
		count--;
		tempbuf1++;
		tempbuf2++;
	}
	return (0);
}
