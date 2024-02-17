/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:38:53 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/15 09:54:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t		ft_strlen(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_load_chunk(char *chunk, int fd, int *le);
long int	ft_find_eol_chunk(char *chunk);
long int	ft_expand_line(long int len, char **line);
long int	ft_shift_reset_chunk(long int len, char *chunk);
int			ft_init_or_expand_line(char **line, long int len);
long int	ft_cpy_line(char **line, char *chunk, long int len);
char		*get_next_line(int fd);

#endif

/*

01	Load chunk
02	copy til \n || end of chunk
03	if copy == end of chunk || >= buffer_size
	reset chunk
	goto 01
04	else found \n
	shift chunk
05	return line

*/