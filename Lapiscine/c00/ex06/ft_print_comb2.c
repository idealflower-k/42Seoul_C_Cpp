#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	change_num(int n)
{
	ft_putchar(n / 10 + '0');
	ft_putchar(n % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			change_num(i);
			ft_putchar(' ');
			change_num(j);
			if (i != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}
