/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:35:52 by seungule          #+#    #+#             */
/*   Updated: 2023/03/24 18:22:45 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	temp;
	char	*ch;
	char	*result;

	ch = (char *)string;
	temp = (char)c;
	result = NULL;
	while (*ch != '\0')
	{
		if (*ch == temp)
			result = ch;
		ch++;
	}
	if (temp == '\0')
		return (ch);
	return (result);
}
