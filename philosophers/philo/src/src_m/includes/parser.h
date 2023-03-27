/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:12 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/27 18:46:33 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	meta_init(t_meta *meta, int ac, char **av);
void	set_number_of_philosophers(t_arg **args, char *av);
void	set_times(t_arg **args, char **av);
void	set_must_eat(t_arg **args, char *av);

/* unit_test */

void	parser_test(t_meta *meta, int ac);

#endif