/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:38:45 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 16:25:59 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*buf;
// 	size_t	i;

// 	buf = (char *)malloc(count * size);
// 	if (buf == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < count * size)
// 		buf[i++] = 0;
// 	return ((void *)buf);
// }

long int	ft_find_eol_chunk(char *chunk)
{
	long int	i;

	i = 0;
	if (chunk[0] == '\n')
		return (1);
	while (i < BUFFER_SIZE && chunk[i] && chunk[i] != '\n')
		i++;
	if (i < BUFFER_SIZE && chunk[i] == '\n')
		i++;
	return (i);
}

long int	ft_expand_line(long int len, char **line)
{
	char		*ol;
	long int	o;

	ol = *line;
	*line = (char *)ft_calloc((ft_strlen(ol) + len + 1), sizeof(char));
	if (*line == NULL)
	{
		*line = ol;
		return (-2);
	}
	o = 0;
	while (ol[o])
	{
		(*line)[o] = ol[o];
		o++;
	}
	if (ol)
	{
		free(ol);
		ol = NULL;
	}
	return (o);
}

int	ft_load_chunk(char *chunk, int fd, int *le)
{
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	*le = read(fd, chunk, BUFFER_SIZE);
	if (*le > 0)
		return (1);
	return (0);
}
