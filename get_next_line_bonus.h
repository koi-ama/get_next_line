/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:59:22 by kamakasu          #+#    #+#             */
/*   Updated: 2024/09/08 23:00:29 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd
{
	int		read_byte;
	char	buff[BUFFER_SIZE];
	char	*buff_ptr;
}			t_fd;

typedef struct s_line
{
	char	*str;
	size_t	len;
	size_t	capacity;
}			t_line;

int			ft_getc(int fd);
void		*ft_memcpy(char *dst, const char *src, size_t n);
int			ft_putc(t_line *line, char c);
char		*get_next_line(int fd);

#endif
