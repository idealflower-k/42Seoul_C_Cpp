/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:04:58 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/29 18:08:22 by sanghwal         ###   ########.fr       */
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

int		ft_printf(const char *str, ...);
int		check_format(va_list ap, t_str *sp, const char *str);
int		ft_print_char(va_list ap, t_str *sp);
int		ft_putchar(char c, t_str *sp);
int		ft_print_str(va_list ap, t_str *sp);
int		ft_putstr(const char *str, t_str *sp);
int		ft_print_pointer(va_list ap, t_str *sp);
void	ft_size(int nb, const int base_len, int *size);
char	*change_to_hexa(int nb);
int		ft_print_int(va_list ap, t_str *sp);
int		ft_print_uint(va_list ap, t_str *sp);
char	*ft_unsigned_itoa(unsigned int n);

#endif