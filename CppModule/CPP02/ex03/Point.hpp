#ifndef POINT_HPP
# define POINT_HPP

class Point {

	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float _fixed_num1, const float fixed_num2);
		Point(const Point& origin);
		Point& operator=(const Point& origin);

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;

		~Point();
};

#endif
