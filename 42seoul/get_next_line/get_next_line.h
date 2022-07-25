/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:16:10 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/25 20:51:42 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				index;
	char			*buf;
	struct s_list	*next;
}					t_list;

char			*get_next_line(int fd);
static t_list	*find_lst(t_list *lst, int fd);
static t_list	*ft_lstnew(void *fd);
#endif