/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:16:10 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/01 20:57:47 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_all(void);
void	free_meta_data(void);
void	detach_threads(pthread_t *threads, int num);
void	destory_forks(int num);
void	destory_philos(int num);

t_bool	ft_atouint64(const char *str, uint64_t *num);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	ft_print_err(const char *str);

#endif