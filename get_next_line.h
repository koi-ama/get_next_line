/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:15:18 by kamakasu          #+#    #+#             */
/*   Updated: 2024/09/08 22:41:59 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_line {
	char	*str;
	size_t len;
	size_t capacity;
} t_line;

typedef struct s_fd {
	int		read_byte;
	char		buff[BUFFER_SIZE];
	char*	buff_ptr;
} t_fd;

#endif
