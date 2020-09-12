/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:09:43 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:09:46 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (alst == 0 || del == 0)
		return ;
	while ((*alst)->next != 0)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		(*alst) = tmp;
	}
	del((*alst)->next, (*alst)->content_size);
	free(*alst);
	*alst = 0;
}
