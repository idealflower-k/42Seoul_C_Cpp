/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:18:07 by sanghwal          #+#    #+#             */
/*   Updated: 2022/12/01 20:28:45 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_cmd
{
	int		pipe[2];
	int		total_cmd;
	char	*cmd_path;
	char	**cmd_info;
}	t_cmd;

typedef struct s_args
{
	int		ac;
	char	**av;
	char	**envp;
	int		io_fd[2];
	int		total_cmd;
	int		status_child;
}	t_args;

t_cmd	**parsing_av(int total, char **av, char *envp[], t_args *args);
t_cmd	**open_and_pars(t_args *arg_info);
t_args	*set_arg_info(int ac, char *av[], char *envp[]);
char	*creat_tmp_file(void);
void	write_on_infile(t_args *arg_info);
void	fork_exec(t_args *args, t_cmd **cmd, int step, int pre_fd);
void	do_wait(pid_t pid, t_args *args, int step);
pid_t	do_fork(void);
char	*get_path(char *cmd, char **envp_path, t_args *args, int i);
char	**parsing_envp(char *envp[]);
char	*make_cmd_path(char *cmd, char *envp_path);
void	make_temp_file(t_args *arg_info);
void	out_file_open(t_args *args);
void	set_fd(t_args *args, int *step_pipe, int step, int pre_fd);
void	*ft_malloc(size_t size);
void	ft_error(char *str);

#endif