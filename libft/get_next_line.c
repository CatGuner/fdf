/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:26:28 by atammie           #+#    #+#             */
/*   Updated: 2019/10/07 18:38:14 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	push_line(char **s, char **line)
{
	size_t	len;
	char	*tmp;
	char	*ptr;

	if (**s == 0)
		return (0);
	ptr = *s;
	len = 0;
	while (*ptr != '\n' && *ptr != 0)
	{
		len++;
		ptr++;
	}
	if (!(*line = ft_memcpy(ft_strnew(len), *s, len)))
		return (-1);
	if (*ptr == 0)
		tmp = ft_strdup("");
	else
	{
		if (!(tmp = ft_strdup(ptr + 1)))
			return (-1);
	}
	free(*s);
	*s = tmp;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			red;
	static char	*s[10240];
	char		*tmp;

	red = 0;
	if (fd < 0)
		return (-1);
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[red] = '\0';
		if (s[fd] == NULL)
			if (!(s[fd] = ft_strnew(BUFF_SIZE)))
				return (-1);
		if (!(tmp = ft_strjoin(s[fd], buf)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n') != 0)
			break ;
	}
	if (red < 0)
		return (-1);
	return (push_line((&s[fd]), line));
}
