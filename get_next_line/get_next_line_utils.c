/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:29:33 by seungule          #+#    #+#             */
/*   Updated: 2023/05/21 14:46:57 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *str, int ch)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (ch == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (str[i] != ch)
		{
			if (str[i] == '\0')
				return (-1);
			i++;
		}
		i += 1;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	int		size_s1;
	int		size_s2;
	int		i;

	i = 0;
	size_s1 = gnl_strlen(s1, '\0');
	size_s2 = gnl_strlen(s2, '\0');
	if (!(size_s1 + size_s2))
		return (NULL);
	result = (char *)malloc(size_s1 + size_s2 + 1);
	if (!result)
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

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;
	size_t	len_s;

	len_s = gnl_strlen(s, 0);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= len_s)
		return (NULL);
	if (len > len_s - start)
		len = len_s - start;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
