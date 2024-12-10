/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:50:50 by gabastos          #+#    #+#             */
/*   Updated: 2024/10/21 14:08:25 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*new_pointer;

	if (!lst)
		return (NULL);
	new_pointer = lst;
	while (new_pointer->next)
		new_pointer = new_pointer->next;
	return (new_pointer);
}
