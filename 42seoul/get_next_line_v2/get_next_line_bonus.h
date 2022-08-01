/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IdealFlower <IdealFlower@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:34:44 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/01 16:48:14 by IdealFlower      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
	struct s_list	*next;
	struct s_list	*before;
}	t_list;

char	*get_next_line(int fd);
t_list	*get_list(t_list **list_head, int fd);
char	*ft_read_save(t_list *fd_list);
char	*ft_get_line(t_list *fd_list);
char	*ft_save(t_list *fd_list);
size_t	ft_strlen(char *str);
size_t	ft_strchr(t_list *fd_list, char c);
t_list	*ft_new_list(int fd);
void	ft_del_list(t_list *fd_list);
char	*ft_strjoin(char *dst, char *src);

#endif