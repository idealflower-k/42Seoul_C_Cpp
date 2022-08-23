/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:04:58 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/23 17:19:52 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_str
{
	int	cnt;
	int	idx;
}	t_str;

int	ft_printf(const char *str, ...);
int	check_format(va_list ap, t_str *sp, const char *str);
int	print_char(va_list ap, t_str *sp);
int	ft_putchar(char c, t_str *sp);

#endif