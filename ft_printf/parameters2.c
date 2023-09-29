/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:49:05 by seungule          #+#    #+#             */
/*   Updated: 2023/06/22 18:51:52 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_size(long int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

int	parameter_u(va_list ap)
{
	long int	temp;
	char		*num;
	int			n_len;
	int			error;

	temp = va_arg(ap, int);
	if (temp < 0)
		temp = 4294967296 + temp;
	n_len = check_size(temp);
	num = (char *)malloc(n_len + 1);
	if (!num)
		return (-1);
	n_len = parameters_u_util(num, n_len, temp);
	error = write(1, num, n_len);
	if (error == -1)
	{
		free(num);
		return (-1);
	}
	free(num);
	return (n_len);
}

int	parameter_x(va_list ap)
{
	unsigned int	num;
	char			number_x[16];
	int				error;
	int				i;

	num = (unsigned int)va_arg(ap, void *);
	if (num == 0)
	{
		error = write(1, "0", 1);
		if (error == -1)
			return (-1);
		return (1);
	}
	if (!num)
		return (0);
	i = parameters_x_util(num, number_x, 87);
	error = write(1, number_x + 16 - i, i);
	if (error == -1)
		return (-1);
	return (i);
}

int	parameter_bigx(va_list ap)
{
	unsigned int	num;
	char			number_x[16];
	int				i;
	int				error;

	i = 0;
	num = (unsigned int)va_arg(ap, void *);
	if (!num)
	{
		error = write(1, "0", 1);
		if (error == -1)
			return (-1);
		return (1);
	}
	i = parameters_x_util(num, number_x, 55);
	error = write(1, number_x + 16 - i, i);
	if (error == -1)
		return (-1);
	return (i);
}

int	parameter_persent(void)
{
	int	error;

	error = write(1, "%%", 1);
	if (error == -1)
		return (-1);
	return (1);
}
