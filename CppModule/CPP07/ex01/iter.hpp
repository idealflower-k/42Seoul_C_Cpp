/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:24:48 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/27 17:13:03 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cmath>

template <typename A, typename F>
void	iter(A* arr, int len, F& func) {
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void	plusOne(T& data) {
	data++;
}

template <typename T>
void	printData(T& data) {
	std::cout << data << ", ";
}

template <typename T, std::size_t N>
std::size_t	arrLen(T (&)[N]) {
	return (N);
}

#endif