/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:11:51 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 16:14:29 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*tmp;
	unsigned char	*data;

	if ((tmp = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		data = (unsigned char*)content;
		if (data && content_size && (tmp->content = \
					(t_list*)ft_memalloc(sizeof(content) * content_size)))
		{
			tmp->content_size = content_size;
			ft_memcpy((tmp->content), content, content_size);
		}
		else
		{
			tmp->content_size = 0;
			tmp->content = NULL;
		}
		tmp->next = 0;
		return (tmp);
	}
	return (0);
}
