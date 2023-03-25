/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:12 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/25 16:26:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parser_args(t_arg **args, int ac, char **av);
void	set_number_of_philosophers(t_arg **args, char *av);
void	set_times(t_arg **args, char **av);
void	set_must_eat(t_arg **args, char *av);

/* unit_test */

void	parser_test(t_arg **args, int ac, char **av);

#endif