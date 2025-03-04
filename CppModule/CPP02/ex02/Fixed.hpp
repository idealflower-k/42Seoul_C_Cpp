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
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed& min(Fixed& num1, Fixed& num2);
		static Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static Fixed& max(const Fixed& num1, const Fixed& num2);
		
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif