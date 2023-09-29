/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:04:26 by seungule          #+#    #+#             */
/*   Updated: 2023/03/26 14:11:35 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		result;

	temp = lst;
	if (lst == NULL)
		return (0);
	result = 1;
	while (temp -> next != NULL)
	{
		temp = temp -> next;
		result++;
	}
	return (result);
}
