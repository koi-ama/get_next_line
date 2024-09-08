/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:52:33 by kamakasu          #+#    #+#             */
/*   Updated: 2024/09/08 19:04:41 by kamakasu         ###   ########.fr       */
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
} t_line;

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

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;
	int					i;

	d = dst;
	s = src;
	printf("memcpyの中\n");
	if (dst == src)
		return (dst);
	if (d < s && d + n > s)
	{
		i = n;
		while (i-- > 0)
			d[i - 1] = s[i - 1];
	}
	else
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dst);
}


int	ft_putc(t_line *line, char c)
{
	char	*new_line;

	printf("putc starts here.\n");
	if (line->capacity <= line->len)
	{
		printf("if_1 の中\n");
		line->capacity = line->len * 2;
		new_line = malloc(line->capacity);
		if (!new_line)
			return (-1);
		ft_memcpy(new_line, line->str, line->len);
		free(line->str);
		line->str = new_line;
	}
	printf("outside of if_1\n");
	line->str[line->len++] = c;
	return (0);
}

int	main(void)
{
	int		fd;
	t_line	line;
	char	c;
	
	line.str = 0;
	line.len = 0;
	line.capacity = 0;
   fd = open("test.txt", O_RDONLY);
   while(1)
   {
	   c = ft_getc(fd);
	   if (c == EOF)
		   break;
	   //'printf("%c", c); これの代わりにft_putc
	   ft_putc(&line, c);
   }
   close(fd);
   printf("%s", line.str);
 return (0);
}
