/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:43:36 by seungule          #+#    #+#             */
/*   Updated: 2023/06/30 13:26:35 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parameter_c(va_list ap)
{
	char	temp;

	temp = va_arg(ap, int);
	return (write(1, &temp, 1));
}

int	parameter_s(va_list ap)
{
	char	*temp;
	size_t	size;
	int		error;

	temp = va_arg(ap, char *);
	if (!temp)
		return (write(1, "(null)", 6));
	size = ft_strlen(temp);
	error = write(1, temp, size);
	if (error == -1)
		return (-1);
	return (size);
}

int	parameter_p(va_list ap)
{
	unsigned long long	memory_address;
	char				mem[16];
	int					i;
	int					error;

	i = 0;
	memory_address = (unsigned long long)va_arg(ap, void *);
	if (memory_address == 0)
	{
		error = write(1, "0x0", 3);
		if (error == -1)
			return (-1);
		return (3);
	}
	i = parameters_p_util(memory_address, mem);
	error = write(1, "0x", 2);
	if (error == -1)
		return (-1);
	error = write(1, mem + 16 - i, i);
	if (error == -1)
		return (-1);
	return (i + 2);
}

int	parameter_d(va_list ap)
{
	int		temp;
	char	*num;
	size_t	size;
	int		error;

	temp = va_arg(ap, int);
	num = ft_itoa(temp);
	if (num == NULL)
	{
		free(num);
		return (-1);
	}
	size = ft_strlen(num);
	error = write(1, num, size);
	if (error == -1)
	{
		free(num);
		return (-1);
	}
	free(num);
	return (size);
}

int	parameter_i(va_list ap)
{
	return (parameter_d(ap));
}
