/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:34:44 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/28 19:55:39 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	size_t			fd;
	ssize_t			read_byte;
	char			buff[BUFFER_SIZE + 1];
	char			*offset;
	struct s_list	*next;
	struct s_list	*before;
}	t_list;

char	*get_next_line(int fd);

#endif