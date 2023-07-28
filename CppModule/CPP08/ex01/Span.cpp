/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:12:22 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/28 21:39:12 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& origin)
    : storage(origin.storage), max_size(origin.max_size) {}

Span& Span::operator=(const Span& origin) {
  if (this != &origin) {
    storage = origin.storage;
    max_size = origin.max_size;
  }
  return (*this);
}
