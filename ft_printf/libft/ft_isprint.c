/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:35:25 by seungule          #+#    #+#             */
/*   Updated: 2023/03/18 11:49:21 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int num)
{
	if (num >= 32 && num <= 126)
		return (1);
	else
		return (0);
}
