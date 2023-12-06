/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:21:19 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/02 16:10:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

#include "Data.hpp"

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer& origin);
  Serializer& operator=(const Serializer& origin);
  ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif
