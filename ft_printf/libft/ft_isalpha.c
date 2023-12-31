/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:32:10 by seungule          #+#    #+#             */
/*   Updated: 2023/03/18 17:09:31 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int num)
{
	if (num >= 65 && num <= 90)
		return (1);
	else if (num >= 97 && num <= 122)
		return (2);
	else
		return (0);
}
