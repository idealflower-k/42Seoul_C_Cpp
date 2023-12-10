/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:40:50 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/10 16:17:19 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data*>(raw));
}

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& origin) { (void)origin; }

Serializer& Serializer::operator=(const Serializer& origin) {
  (void)origin;
  return (*this);
}

Serializer::~Serializer() {}
