/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:07:13 by sanghwal          #+#    #+#             */
/*   Updated: 2022/08/23 17:46:06 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_str	*sp;
	
	va_start(ap, str);
	sp = malloc(sizeof(t_str));
	ft_memset(sp, 0, sizeof(sp));
	while (str[sp->idx] == 0)
	{
		if (str[sp->idx] == '%')
		{
			sp->idx++;
			if (!check_format(ap, sp, str))
				return (-1);
			sp->idx++;
		}
		else
			ft_putchar_fd(str[sp->idx], 1);
	}
	return (sp->cnt);
}

int	check_format(va_list ap, t_str *sp, const char *str)
{
	if (str[sp->idx] == '%')
		ft_putchar('%', sp);
	else if (str[sp->idx] == 'c')
		ft_putchar_pf(ap, sp);
	else if (str[sp->idx] == 's')
		ft_putstr_pf(ap, sp);
	else if (str[sp->idx] == 'p')
	// 주소값을 16진법으로 변환하여 출력 (void *)va_arg(ap, unsigned long) 형식으로 받아서 형변환
	else if (str[sp->idx] == 'd')
		
	else if (str[sp->idx] == 'i')
	// d 와 동일
	else if (str[sp->idx] == 'u')
	// unsigned int 출력(절대값)
	else if (str[sp->idx] == 'x')
	// 16진법 소문자
	else if (str[sp->idx] == 'X')
	// 16진법 대문자
	else // 없는 형식지정자 에러
		return (-1);
	return (0);
}
