/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:31:51 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:02:47 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set || s1[start] == '\0')
		return (ft_strdup(""));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
	{
		if (end - 1 < 1)
			break ;
		end--;
	}
	if (start >= end)
		return (ft_strdup(""));
	result = (char *)malloc(end - start + 1);
	if (result == 0)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
