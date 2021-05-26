/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:35:15 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/04 11:59:49 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *lastlst;

	lastlst = 0;
	if (lst)
		lastlst = lst;
	while (lastlst && lastlst->next)
		lastlst = lastlst->next;
	return (lastlst);
}
