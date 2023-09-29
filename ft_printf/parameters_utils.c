/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:32:32 by seungule          #+#    #+#             */
/*   Updated: 2023/06/22 18:52:33 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parameters_p_util(unsigned long long ma, char *mem)
{
	int					i;
	unsigned long long	temp;

	i = 0;
	while (ma != 0)
	{
		i++;
		temp = ma % 16;
		ma = ma / 16;
		if (temp >= 10 && temp <= 15)
			mem[16 - i] = temp + 87;
		else
			mem[16 - i] = temp + '0';
	}
	return (i);
}

int	parameters_u_util(char *num, int n_len, long int temp)
{
	num[n_len] = '\0';
	if (temp == 0)
		num[0] = '0';
	while (temp)
	{
		num[n_len - 1] = temp % 10 + 48;
		temp = temp / 10;
		n_len--;
	}
	n_len = ft_strlen(num);
	return (n_len);
}

int	parameters_x_util(unsigned int num, char *number_x, int print_ch)
{
	unsigned int	temp;
	int				i;

	i = 0;
	while (num != 0)
	{
		temp = num % 16;
		num = num / 16;
		if (temp >= 10 && temp <= 15)
			number_x[15 - i++] = temp + print_ch;
		else
			number_x[15 - i++] = temp + '0';
	}
	return (i);
}
