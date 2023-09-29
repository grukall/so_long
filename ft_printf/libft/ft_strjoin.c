/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:21:36 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:02:17 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size_s1;
	int		size_s2;
	int		i;

	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	result = (char *)malloc(size_s1 + size_s2 + 1);
	if (result == 0)
		return (NULL);
	while (i < size_s1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < size_s1 + size_s2)
	{
		result[i] = s2[i - size_s1];
		i++;
	}
	result[i] = '\0';
	return (result);
}
