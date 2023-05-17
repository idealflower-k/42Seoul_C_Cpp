/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:37:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/17 15:02:52 by sanghwal         ###   ########seoul.kr  */
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

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		float	operator+(const Fixed& other);
		float	operator-(const Fixed& other);
		float	operator*(const Fixed& other);
		float	operator/(const Fixed& other);
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const; // 고정소수점 값을 부동 소수점 값으로 변환하는 함수
		int		toInt(void) const; // 고정소수점 값을 정수 값으로 변환하는 함수

		static Fixed& min(Fixed& num1, Fixed& num2);
		static Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static Fixed& max(const Fixed& num1, const Fixed& num2);
		
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif