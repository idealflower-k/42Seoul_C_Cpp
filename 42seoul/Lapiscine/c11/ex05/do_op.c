/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:24:37 by sanghwal          #+#    #+#             */
/*   Updated: 2022/05/05 14:16:35 by sanghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		add(int a, int b);
int		min(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	ft_atoi(char *str)
{
	int	sign;
	int	temp;

	temp = 0;
	sign = 1;
	while (*str)
	{
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			temp = (temp * 10) + (*str - '0');
			str++;
		}
		return (sign * temp);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb > 2147483647 || nb < -2147483648)
	{
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
}

int	check_op(char *op, int b)
{
	if (*op != '+' && *op != '-' && *op != '*'
		&& *op != '/' && *op != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (*op == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (*op == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

void	op(int a, int b, char *oper)
{
	int	(*ft_math[5])(int, int);

	ft_math[0] = add;
	ft_math[1] = min;
	ft_math[2] = mul;
	ft_math[3] = div;
	ft_math[4] = mod;
	if (*oper == '+')
		ft_putnbr(ft_math[0](a, b));
	else if (*oper == '-')
		ft_putnbr(ft_math[1](a, b));
	else if (*oper == '*')
		ft_putnbr(ft_math[2](a, b));
	else if (*oper == '/')
		ft_putnbr(ft_math[3](a, b));
	else if (*oper == '%')
		ft_putnbr(ft_math[4](a, b));
}

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	nbr;

	if (ac == 4)
	{	
		nbr = 0;
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		if (check_op(av[2], b) == 0)
			return (0);
		else
		{
			op(a, b, av[2]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
