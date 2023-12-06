/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:38:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/06 15:54:22 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
  std::string name;
  unsigned int age;
  unsigned int level;

  Data() : name(""), age(0), level(0){};
  Data(std::string name, unsigned int age, unsigned int level)
      : name(name), age(age), level(level){};
};

#endif
