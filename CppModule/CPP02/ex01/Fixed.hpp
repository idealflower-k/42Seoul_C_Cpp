/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:22:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/20 23:24:58 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
class Fixed {

	private:
		static const int	fractional_bits;
		int					fixed_point_num;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float f_num);
		Fixed(const Fixed& origin);

		Fixed& operator=(const Fixed& origin);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
