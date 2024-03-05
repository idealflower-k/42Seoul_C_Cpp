#include <unistd.h>

int	is_queen(char *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (board[i] == board[n])
			return (0);
		if (i + board[i] == n + board[n] || i - board[i] == n - board[n])
			return (0);
		i++;
	}
	return (1);
}

void	set_queen(char *board, int n, int *count)
{
	if (is_queen(board, n))
	{
		if (n == 9)
		{
			*count += 1;
			write(1, board, 10);
			write(1, "\n", 1);
		}
		else
		{
			board[n + 1] = '0';
			set_queen(board, n + 1, count);
		}
	}
	if (board[n] < '9')
	{
		board[n] += 1;
		set_queen(board, n, count);
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		count;

	board[0] = '0';
	count = 0;
	set_queen(board, 0, &count);
	return (count);
}
