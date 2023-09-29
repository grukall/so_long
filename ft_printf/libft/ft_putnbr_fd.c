/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:28:54 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 10:01:49 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lennbr(int n)
{
	int	result;

	result = 0;
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[10];
	int		n_len;
	int		i;

	i = 0;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	n_len = ft_lennbr(n);
	while (n_len >= 1 + i)
	{
		if (n > 0)
			temp[n_len - 1 - i] = n % 10 + '0';
		if (n < 0)
		temp[n_len - 1 - i] = n % 10 * -1 + '0';
		n = n / 10;
		i++;
	}
	write (fd, temp, n_len);
}
