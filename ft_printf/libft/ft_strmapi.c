/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:31:20 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:02:34 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len_s;
	char	*temp;
	int		i;

	i = -1;
	len_s = ft_strlen(s);
	temp = (char *)malloc(len_s + 1);
	if (temp == NULL)
		return (NULL);
	temp[len_s] = '\0';
	while (++i < len_s)
		temp[i] = f(i, s[i]);
	return (temp);
}
