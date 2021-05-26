/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:07:25 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/18 11:37:45 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;

	if (lst && del)
	{
		while (*lst)
		{
			ptr = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(ptr, del);
		}
		*lst = 0;
	}
}
