/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:04:43 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:02:09 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*str;

	len = 0;
	while (src[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		str[len] = ((char *)src)[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
