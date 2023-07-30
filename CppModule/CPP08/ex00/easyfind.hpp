/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:23:25 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/30 17:44:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
typename T::const_iterator easyfind(const T& contain, unsigned int value) {
  typename T::const_iterator citr =
      std::find(contain.begin(), contain.end(), value);
  return (citr);
}

#endif
