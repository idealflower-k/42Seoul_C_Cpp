/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:16:10 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/31 16:00:44 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	error_handler(int err_num);
void	detach_threads(pthread_t *threads);
void	destory_forks(void);

t_bool	ft_atouint64(const char *str, uint64_t *num);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	ft_print_err(const char *str);

#endif