/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:55:50 by seungule          #+#    #+#             */
/*   Updated: 2023/03/19 17:25:53 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	char	*ch;
	char	temp;

	ch = (char *)string;
	temp = (char)c;
	while (*ch != '\0')
	{
		if (*ch == temp)
			return (ch);
		ch++;
	}
	if (temp == '\0')
		return (ch);
	else
		return (NULL);
}
