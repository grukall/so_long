/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:56:11 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:01:26 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int num, size_t count)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		temp[i] = (unsigned char)num;
		i++;
	}
	return (temp);
}
