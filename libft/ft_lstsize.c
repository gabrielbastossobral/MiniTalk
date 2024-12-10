/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:23:53 by gabastos          #+#    #+#             */
/*   Updated: 2024/10/24 16:20:43 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*new_pointer;

	count = 0;
	new_pointer = lst;
	while (new_pointer != NULL)
	{
		new_pointer = new_pointer->next;
		count++;
	}
	return (count);
}
