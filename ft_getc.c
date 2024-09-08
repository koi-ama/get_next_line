/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:52:33 by kamakasu          #+#    #+#             */
/*   Updated: 2024/09/08 18:24:49 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_line {
	char	*str;
	size_t len;
	size_t capacity;
} t_line

char	ft_getc(int fd)
{
	static int	read_byte;
	static char	buff[BUFFERSIZE];
	static char* buff_ptr;

	if (read_byte == 0)
	{
		read_byte = read(fd, buff, BUFFERSIZE);
		buff_ptr = buff;
	}
	printf("%d\n", read_byte);
	read_byte--;
	if (read_byte < 0)
		return (EOF);
	return (*buff_ptr++);
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
		memcpy(new_line, line->str, line->len + 1);
		free(line->str);
		line->str = new_line;
	}
	line->str[line->len++] = c;
}

int	main(void)
{
	 int fd;
   char *line;
   int aoshi = 42;

   printf("EOF = %d\n", EOF);

   fd = open("test.txt", O_RDONLY);
   char c;
   while(1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break;
		//'printf("%c", c); これの代わりにft_putc
	}
 	close(fd);
 return (0);
}
