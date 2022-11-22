/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:18:07 by sanghwal          #+#    #+#             */
/*   Updated: 2022/11/22 16:47:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_cmd_node
{
	int		pipe[2];
	int		total_cmd;
	int		executable;
	char	*cmd_path;
	char	**cmd_info;
}	t_cmd_node;

typedef struct s_args
{
	int		ac;
	char	**av;
	char	**envp;
	int		file_fd[2];
}	t_args;


t_cmd_node	**parsing_av(int total, char **av, char *envp[]);
void		recursive_fork(t_args *arg_info, t_cmd_node **cmd_arr, int step, int pre_fd);
char		*get_path(char *cmd, char **envp_path);
char		**parsing_envp(char *envp[]);
char		*make_cmd_path(char *cmd, char *envp_path);
void		*ft_malloc(size_t size);

#endif