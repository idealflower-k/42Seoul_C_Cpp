/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:37:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/11 18:41:48 by sanghwal         ###   ########seoul.kr  */
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
		Fixed(const int num); // num을 해당 고정소수점 값으로 변환. 소수 비트 값은 8로 초기화
		Fixed(const float f_num); // f_num을 해당 고정소수점 값으로 변환. 소수 비트 값은 8로 초기화
		Fixed(const Fixed& origin);

		Fixed& operator=(const Fixed& origin);
		Fixed& operator>(const Fixed& origin);
		Fixed& operator<(const Fixed& origin);
		Fixed& operator>=(const Fixed& origin);
		Fixed& operator<=(const Fixed& origin);
		Fixed& operator==(const Fixed& origin);
		Fixed& operator!=(const Fixed& origin);
		Fixed& operator+(const Fixed& origin);
		Fixed& operator-(const Fixed& origin);
		Fixed& operator+(const Fixed& origin);
		Fixed& operator/(const Fixed& origin);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const; // 고정소수점 값을 부동 소수점 값으로 변환하는 함수
		int		toInt(void) const; // 고정소수점 값을 정수 값으로 변환하는 함수
		int&	min(int& fixed_num1, int& fixed_num2);
		int&	min(const int& fixed_num1, const int& fixed_num2);
		int&	max(int& fixed_num1, int& fixed_num2);
		int&	max(const int& fixed_num1, const int& fixed_num2);
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif