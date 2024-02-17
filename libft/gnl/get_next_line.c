/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:38:49 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 11:49:03 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long int	ft_shift_reset_chunk(long int len, char *chunk)
{
	long int	i;

	i = 0;
	if (len >= BUFFER_SIZE)
	{
		while (i < BUFFER_SIZE)
			chunk[i++] = 0;
		return (BUFFER_SIZE);
	}
	while (len < BUFFER_SIZE && chunk[len])
		chunk[i++] = chunk[len++];
	while (i < BUFFER_SIZE)
		chunk[i++] = 0;
	return (i);
}

int	ft_init_or_expand_line(char **line, long int len)
{
	int	o;

	o = 0;
	if (*line == NULL)
	{
		*line = (char *)ft_calloc((len + 1), sizeof(char));
		if (*line == NULL)
			return (-2);
	}
	else
		o = ft_expand_line(len, line);
	return (o);
}

long int	ft_cpy_line(char **line, char *chunk, long int len)
{
	long int	i;
	long int	o;

	i = 0;
	o = 0;
	o = ft_init_or_expand_line(line, len);
	if (o == -2)
		return (-2);
	while (i <= len && i < BUFFER_SIZE && chunk[i])
	{
		(*line)[o + i] = chunk[i];
		if (i < BUFFER_SIZE && chunk[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	ft_shift_reset_chunk(len, chunk);
	if ((*line)[i + o - 1] == '\n')
		len = -1;
	return (len);
}

void	ft_handle_loaderror(int loaderror, char *chunk, char **line)
{
	size_t	i;

	if (loaderror < 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			chunk[i++] = 0;
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	chunk[BUFFER_SIZE];
	char		*line;
	long int	len;
	int			loaderror;

	line = NULL;
	len = 0;
	loaderror = 0;
	while (chunk[0] || ft_load_chunk(chunk, fd, &loaderror))
	{
		len = ft_find_eol_chunk(chunk);
		len = ft_cpy_line(&line, chunk, len);
		if (len < 0)
		{
			if (len == -2 && line)
			{
				free(line);
				line = NULL;
			}
			break ;
		}
	}
	ft_handle_loaderror(loaderror, chunk, &line);
	return (line);
}
