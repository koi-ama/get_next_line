/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:27:21 by kamakasu          #+#    #+#             */
/*   Updated: 2024/09/08 23:30:49 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_getc(int fd)
{
	static t_fd	fd_list[FOPEN_MAX];

	if (fd_list[fd].read_byte == 0)
	{
		fd_list[fd].read_byte = read(fd, fd_list[fd].buff, BUFFER_SIZE);
		if (fd_list[fd].read_byte < 0)
			return (fd_list[fd].read_byte++, -42);
		fd_list[fd].buff_ptr = fd_list[fd].buff;
	}
	fd_list[fd].read_byte--;
	if (fd_list[fd].read_byte < 0)
		return (fd_list[fd].read_byte++, EOF);
	return (*fd_list[fd].buff_ptr++);
}

void	*ft_memcpy(char *dst, const char *src, size_t n)
{
	while (n--)
	{
		*dst++ = *src++;
	}
	return (dst);
}

int	ft_putc(t_line *line, char c)
{
	char	*new_line;

	if (line->capacity <= line->len)
	{
		line->capacity = line->len * 2;
		new_line = malloc(line->capacity);
		if (!new_line)
			return (-1);
		ft_memcpy(new_line, line->str, line->len);
		free(line->str);
		line->str = new_line;
	}
	line->str[line->len++] = c;
	return (0);
}

char	*get_next_line(int fd)
{
	t_line	line;
	char	c;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line.str = 0;
	line.len = 0;
	line.capacity = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		if (c == -42)
			return (free(line.str), NULL);
		if (ft_putc(&line, c) == -1)
			return (free(line.str), NULL);
		if (c == '\n')
			break ;
	}
	if (!line.len)
		return (NULL);
	ft_putc(&line, '\0');
	return (line.str);
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*cat_ptr;
	char	*cat_ptr2;

	fd = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (1)
	{
		cat_ptr = get_next_line(fd);
		cat_ptr2 = get_next_line(fd2);
		printf("%s", cat_ptr);
		printf("%s", cat_ptr2);
		if (!cat_ptr || !cat_ptr2)
			break ;
	}
	close(fd);
	return (0);
}
*/
