/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:04:00 by seungule          #+#    #+#             */
/*   Updated: 2023/06/22 21:08:26 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int	find_parameter(const char temp, va_list ap);
int	go_parameter(const char parameter, va_list ap);
int	ft_printf(const char *str, ...);
int	parameter_c(va_list ap);
int	parameter_s(va_list ap);
int	parameter_p(va_list ap);
int	parameter_d(va_list ap);
int	parameter_i(va_list ap);
int	parameter_u(va_list ap);
int	parameter_x(va_list ap);
int	parameter_bigx(va_list ap);
int	parameter_persent(void);
int	parameters_p_util(unsigned long long ma, char *mem);
int	parameters_u_util(char *num, int n_len, long int temp);
int	parameters_x_util(unsigned int num, char *number_x, int print_ch);
int	print_parameter(const char *str, va_list ap);
int	find_percentage(const char *str, int i, va_list ap);
int	calculate_i(int i, int error);

#endif
