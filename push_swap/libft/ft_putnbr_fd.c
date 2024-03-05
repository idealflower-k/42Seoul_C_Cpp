#include "libft.h"

void		ft_putnbr_fd(int n, int fd);
static void	ft_putchar(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n > 2147483647 || n < -2147483648)
		return ;
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar(n, fd);
}

static void	ft_putchar(int n, int fd)
{
	n = n + '0';
	write(fd, &n, 1);
}
