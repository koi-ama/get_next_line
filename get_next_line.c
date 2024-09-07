/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:16:10 by kamakasu          #+#    #+#             */
/*   Updated: 2024/09/07 23:01:59 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_line {
	char *str;
	size_t len;
	size_t capacity;
} t_line;

char ft_getc(int fd)
{
	static char *buff;
	static int read_byte;
	
	if (read_byte <= 0)
		read_byte = read(fd, buff, BUFFER_SIZE);
	read_byte--;
	return (*buff++);
}

int ft_putc(t_line *line, char c)
{
	if (line->capacity <= line->len)
	{
		line->capacity = line->len * 2;
		char *new_line = malloc(line->capacity);
		if (!new_line)
			return -1;
		memcpy(new_line, line->str);
		free(line->str);
		line->str = new_line;
	}
	line->str[line->len++] = c;
}



char*	get_next_line(int fd);
{
	char *result;
	t_line line;
	
	line.str = 0;
	line.len = 0;
	line.capacity = 0;
	while (1)
	{
		char c = ft_getc(fd);
		if (c == EOF)
			break;
		ft_putc(&line, c);
		if (c == '\n')
			break;
	}
	ft_putc(&line, '\0');
	return (line->str);
}
