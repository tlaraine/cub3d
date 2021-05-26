/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:10:36 by tlaraine          #+#    #+#             */
/*   Updated: 2021/01/17 18:33:25 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *newlst;

	if (!lst)
		return ;
	else if (!*lst)
		*lst = new;
	else if (new)
	{
		newlst = ft_lstlast(*lst);
		newlst->next = new;
	}
}
