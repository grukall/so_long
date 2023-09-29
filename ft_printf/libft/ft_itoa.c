/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:15:52 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:00:18 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_size(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		result++;
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		n_len;

	n_len = ft_check_size(n);
	temp = (char *)malloc(n_len + 1);
	if (temp == NULL)
		return (NULL);
	temp[n_len] = '\0';
	if (n < 0)
		temp[0] = '-';
	if (n == 0)
	{
		temp[0] = '0';
		return (temp);
	}
	while (n)
	{
		if (n > 0)
			temp[n_len - 1] = n % 10 + 48;
		else
			temp[n_len - 1] = n % 10 * -1 + 48;
		n = n / 10;
		n_len--;
	}
	return (temp);
}
