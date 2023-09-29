/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:16:45 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:01:01 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*temp;

	temp = (void *)malloc(size * num);
	if (temp == 0)
		return (NULL);
	ft_memset(temp, 0, num * size);
	return (temp);
}
