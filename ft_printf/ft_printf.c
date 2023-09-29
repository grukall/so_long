/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:26:00 by seungule          #+#    #+#             */
/*   Updated: 2023/06/26 15:44:59 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, str);
	result = print_parameter(str, ap);
	va_end(ap);
	return (result);
}

int	print_parameter(const char *str, va_list ap)
{
	int		count;
	int		i;
	int		error;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		error = find_percentage(str, i, ap);
		i = calculate_i(i, error);
		if (error == -1)
			return (-1);
		else if (error == -2)
			continue ;
		else if (error == 0)
			count++;
		else
			count += error;
	}
	return (count);
}

int	find_percentage(const char *str, int i, va_list ap)
{
	int	error;
	int	result;

	if (str[i] == '%')
	{
		result = find_parameter(str[i + 1], ap);
		if (result == 0 && str[i + 1] != 's')
			error = write(1, &str[i], 1);
		else if (result == -1)
			return (-1);
		if (result == 0 && str[i + 1] == 's')
			return (-2);
		if (error == -1)
			return (-1);
		return (result);
	}
	else
		error = write(1, &str[i], 1);
	if (error == -1)
		return (-1);
	return (0);
}

int	calculate_i(int i, int error)
{
	if (error == 0)
		return (i + 1);
	else
		return (i + 2);
}
