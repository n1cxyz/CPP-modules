#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed ();
		Fixed (const int number);
		Fixed (const float);
		Fixed (const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed);
		~Fixed ();
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					rawBits;
		static const int	fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &op, const Fixed &a);

#endif