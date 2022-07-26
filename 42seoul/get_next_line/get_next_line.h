/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:16:10 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/26 21:40:07 by sanghwal         ###   ########.fr       */
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
	char			*old_buf;
	struct s_list	*next;
}					t_list;

char			*get_next_line(int fd);
void		read_split(int fd, t_list *lst);
char		*ft_resultdup(char *old_buf);
void		ft_delnode(t_list **lst_head, int fd);
t_list	*find_lst(t_list **lst, int fd);
t_list	*ft_lstnew(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);
ssize_t	ft_strchr(char const *str, char c);
#endif