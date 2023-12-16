/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:23:25 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/16 19:05:15 by sanghwal         ###   ########seoul.kr  */
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
typename T::const_iterator easyfind(const T& contain, int value) {
  typename T::const_iterator citr =
      std::find(contain.begin(), contain.end(), value);
  return (citr);
}

template <typename T>
typename T::const_iterator easyfind(const T& contain,
                                    typename T::value_type value) {
  typename T::const_iterator citr =
      std::find(contain.begin(), contain.end(), value);
  return (citr);
}

#endif
