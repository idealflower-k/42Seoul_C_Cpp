/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:23:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/23 20:13:01 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

// int strcmp(char *str1, char *str2)
// {
// 	int i = 0;
// 	while (str1[i] != '\0' && str2[i] != '\0')
// 	{
// 		if (str1[i] != str2[i])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	cmd_len(int ac, char** av)
{
	int	i = 0;
	while (av[ac] != NULL && strcmp(av[ac], "|") && strcmp(av[ac], ";"))
	{
		printf("%s\n", av[ac]);
		i++;
		ac++;
	}
	return (i);
}

int	main(int ac, char** av, char** envp)
{
	t_list	*meta_list = NULL;

	if (ac == 1)
		exit (0);
	int i = cmd_len(1, av);
	printf("i: %d\n", i);
	parser(meta_list, ac, av);
}


void	make_cmd_list(int *ac, char **av, t_list *meta)
{
	t_cmd	*new = NULL;
}

void	parser(t_list *meta, int ac, char **av)
{
	int i = 0;
	while (i < ac) {
		make_cmd_list(&ac, av, meta);
	}
}

void	cmd_list_add(t_list **cmd, t_list *new) {
	t_list	*temp = *cmd;

	if (*cmd == NULL)
	{
		*cmd = new;
		return (*cmd);
	}

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_list*	meta_list_add(t_list **meta, t_list *new)
{
	t_list	*temp = *meta;

	if (*meta == NULL)
	{
		*meta = new;
		return (*meta);
	}

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (*meta);
}
