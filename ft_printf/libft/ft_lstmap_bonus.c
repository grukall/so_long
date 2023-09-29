/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:15:38 by seungule          #+#    #+#             */
/*   Updated: 2023/03/31 20:52:46 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*result;
	void	*temp2;

	result = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		temp2 = f(lst -> content);
		temp = ft_lstnew(temp2);
		if (!temp)
		{
			del(temp2);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		lst = lst -> next;
	}
	return (result);
}
