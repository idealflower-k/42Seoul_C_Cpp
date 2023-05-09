/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:13:15 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/09 15:29:24 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		static const int	fractional_bits = 8;
		int					fixed_point_num;
	public:
		Fixed();
		Fixed(const Fixed& origin);
		Fixed& operator=(const Fixed& origin);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
};

#endif
