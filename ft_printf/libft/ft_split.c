/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:44:08 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:02:02 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(const char *s, char c);
char	*make_str(char *s, char c);
char	**ft_free(char **str_arr, int str_arr_index);

char	**ft_split(char const *s, char c)
{
	int		str_arr_index;
	char	**str_arr;

	str_arr_index = 0;
	str_arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			str_arr[str_arr_index] = make_str((char *)s, c);
			if (str_arr[str_arr_index] == 0)
				return (ft_free(str_arr, str_arr_index));
			str_arr_index++;
		}
		while (*s && *s != c)
			s++;
	}
	str_arr[str_arr_index] = 0;
	return (str_arr);
}

char	**ft_free(char **str_arr, int str_arr_index)
{
	while (str_arr_index >= 0)
	{
		free(str_arr[str_arr_index]);
		str_arr_index--;
	}
	free(str_arr);
	return (NULL);
}

int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	if (*s != c && *s != '\0')
		count++;
	while (*s != '\0')
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			count++;
		s++;
	}
	return (count);
}

char	*make_str(char *s, char c)
{
	int		str_len;
	int		i;
	char	*new_str;

	str_len = 0;
	i = 0;
	while (*(s + str_len) && *(s + str_len) != c)
		str_len++;
	if (str_len == 0)
		return (0);
	new_str = (char *)malloc(str_len * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	while (i < str_len)
	{
		new_str[i] = *s;
		i++;
		s++;
	}
	new_str[i] = 0;
	return (new_str);
}
