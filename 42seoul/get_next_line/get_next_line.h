/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:04:38 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/17 15:58:58 by sanghwal         ###   ########.fr       */
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
	int				fd;
	ssize_t			read_byte;
	char			*result;
	char			buff[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_read_save(t_list *list);
char	*ft_get_line(t_list *list);
char	*ft_save(t_list *list, t_list **head);
t_list	*get_list(t_list **list_head, int fd);
char	*ft_del_list(t_list *list, t_list **head);
size_t	ft_strchr(t_list *list, char c);
size_t	ft_strlen(char *str);
t_list	*ft_new_list(int fd);
char	*ft_strjoin(char *dst, char *src);

#endif