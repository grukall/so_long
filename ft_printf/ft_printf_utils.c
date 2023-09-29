/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:30:41 by seungule          #+#    #+#             */
/*   Updated: 2023/06/22 18:13:54 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_parameter(char	*parameter)
{
	parameter[0] = 'c';
	parameter[1] = 's';
	parameter[2] = 'p';
	parameter[3] = 'd';
	parameter[4] = 'i';
	parameter[5] = 'u';
	parameter[6] = 'x';
	parameter[7] = 'X';
	parameter[8] = '%';
}

int	find_parameter(const char temp, va_list ap)
{
	char	parameter[9];
	int		i;

	i = 0;
	make_parameter(parameter);
	if (temp == '\0')
		return (0);
	while (i < 9)
	{
		if (temp == parameter[i])
			return (go_parameter(temp, ap));
		i++;
	}
	return (0);
}

int	go_parameter(const char parameter, va_list ap)
{
	int	result;

	result = 1;
	if (parameter == 'c')
		result = parameter_c(ap);
	else if (parameter == 's')
		result = parameter_s(ap);
	else if (parameter == 'p')
		result = parameter_p(ap);
	else if (parameter == 'd')
		result = parameter_d(ap);
	else if (parameter == 'i')
		result = parameter_i(ap);
	else if (parameter == 'u')
		result = parameter_u(ap);
	else if (parameter == 'x')
		result = parameter_x(ap);
	else if (parameter == 'X')
		result = parameter_bigx(ap);
	else if (parameter == '%')
		result = parameter_persent();
	if (result == -1)
		return (-1);
	return (result);
}
