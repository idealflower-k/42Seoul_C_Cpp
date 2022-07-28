/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:39:17 by sanghwal          #+#    #+#             */
/*   Updated: 2022/07/28 20:20:55 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static t_list	*list_head;
	t_list			*fd_list;
	char			*result;

	if (fd < 0)
		return (0);
	fd_list = get_list(&(list_head), fd);
	if (!fd_list)
		return (0);

}

	// fd 값을 가지고 있는 list를 탐색한다.
t_list	*get_list(t_list **list_head, int fd);
	// 없으면 생성
t_list	*ft_new_list(int fd);
	// fd_list.buff에 값이 남아있는지 확인
char	*ft_check_buff(t_list *fd_list, int fd);
	// 없으면 read
char	*ft_read_save(t_list *fd_list);
	// read 로 eof를 받으면 노드 삭제후 널 리턴
	// 읽은 바이트를 받으면 fd_list.buff 에 저장된 값을 개행 검사
ssize_t	ft_strchr(char *str, char c);
	// 개행이 있으면 개행 까지 복사해서 리턴해주고 fd_list.buff 의 값을 변경해준다.
	// 개행이 없으면 fd_list.buff의 내용을 임시 공간에 할당해서 복사한 후 read를 통해 fd_list.buff 내용 변경 후 개행검사
	// 개행이 있으면 임시 공간 뒤에 복사해주고 fd_list.buff 변경
char	*ft_strjoin(char *dst, char *src);
	// 개행이 있으면 그만큼을 복사해 리턴해준다. 뒤에 내용을 fd_list.buff에 넣어준다.
	// read 해서 eof를 받았다면 남은 문자열을 복사해서 다 리턴해주고 노드를 삭제해준다.
void	ft_del_list(t_list *fd_list);
char	*ft_make_result(t_list *fd_list);

t_list	*get_list(t_list **list_head, int fd)
{
	t_list	*temp;

	temp = *list_head;
	if (*list_head == 0)
	{
		temp = ft_new_list(fd);
		if (!temp)
			return (0);
		*list_head = temp;
		return (temp);
	}
	while (temp)
	{
		if (temp ->fd == fd)
			break ;
		if (temp ->next == 0)
		{
			temp ->next = ft_new_list(fd);
			if (!(temp ->next))
				return (0);
			temp ->next ->before = temp;
		}
		temp = temp ->next;
	}
	return (temp);
}

t_list	*ft_new_list(int fd)
{
	t_list	*new;
	size_t	i;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new ->fd = fd;
	new ->next = 0;
	new ->offset = 0;
	new ->read_byte = 0;
	new ->before = 0;
	i = 0;
	while (i <= BUFFER_SIZE)
		new ->buff[i++] = 0;
	return (new);
}

ssize_t	ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_check_buff(t_list *fd_list, int fd)
{
	size_t	i;
	char	*line;

	line = 0;
	if (!fd_list ->buff[0])
	{
		line = ft_read_save(fd_list);
	}

	return (line);
}

char	*ft_read_save(t_list *fd_list)
{
	fd_list ->read_byte = read(fd_list ->fd, fd_list ->buff, BUFFER_SIZE);
	if (fd_list ->read_byte == -1)
	{
		ft_del_list(fd_list);
		return (0);
	}
}

void	ft_del_list(t_list *fd_list)
{
	t_list	*temp;
	t_list	*del;

	temp = fd_list ->before;
	if (!temp)
	{
		del = fd_list;
		fd_list = fd_list ->next;
		free(del);
		return ;
	}
	temp ->next = fd_list ->next;
	free(fd_list);
}