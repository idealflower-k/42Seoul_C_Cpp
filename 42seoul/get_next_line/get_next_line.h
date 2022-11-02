/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:04:38 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/02 19:31:30 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl_list
{
	int					fd;
	ssize_t				read_byte;
	char				*result;
	char				buff[BUFFER_SIZE + 1];
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
char		*gnl_read_save(t_gnl_list *list);
char		*gnl_get_line(t_gnl_list *list);
char		*gnl_save(t_gnl_list *list, t_gnl_list **head);
char		*gnl_del_list(t_gnl_list *list, t_gnl_list **head);
size_t		gnl_strchr(t_gnl_list *list, char c);
size_t		gnl_strlen(char *str);
char		*gnl_strjoin(char *dst, char *src);
t_gnl_list	*gnl_new_list(int fd);
t_gnl_list	*get_list(t_gnl_list **list_head, int fd);

#endif