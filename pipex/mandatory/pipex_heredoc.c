#include "pipex.h"

void	make_temp_file(t_args *arg_info)
{
	char	*tmp_file;

	tmp_file = creat_tmp_file();
	arg_info->io_fd[0] = open(tmp_file, O_WRONLY | O_CREAT, 0644);
	if (arg_info->io_fd[0] == -1)
		perror("temp file open() error");
	write_on_infile(arg_info);
	close(arg_info->io_fd[0]);
	arg_info->io_fd[0] = open(tmp_file, O_RDONLY);
	unlink(tmp_file);
	free(tmp_file);
}

void	write_on_infile(t_args *arg_info)
{
	char	*gnl;

	while (1)
	{
		write(1, "here_doc> ", 10);
		gnl = get_next_line(0);
		if (ft_strncmp(gnl, arg_info->av[2], ft_strlen(gnl) - 1) == 0 && \
			ft_strlen(gnl) - 1 == ft_strlen(arg_info->av[2]))
		{
			free(gnl);
			break ;
		}
		if (write(arg_info->io_fd[0], gnl, ft_strlen(gnl)) == -1)
			perror("infile write error()");
		free(gnl);
	}
}

char	*creat_tmp_file(void)
{
	char	*result;
	char	*num_str;
	int		num;

	num = 0;
	num_str = ft_itoa(num);
	result = ft_strjoin("/tmp/pipex_tmp", num_str);
	while (result)
	{	
		if (access(result, F_OK) != 0)
			break ;
		free(num_str);
		free(result);
		num_str = ft_itoa(num++);
		result = ft_strjoin("/tmp/pipex_tmp", num_str);
	}
	free(num_str);
	return (result);
}
