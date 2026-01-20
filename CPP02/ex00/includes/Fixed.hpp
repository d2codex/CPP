#ifndef FIXED_HPP
#define FIXED_HPP

#ifdef DBUG
#define DBG(x) x
#else
#define DBG(x)
#endif

#include "Logger.hpp"

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

//	int	getRawBits(void) const;
//	int setRawBits(int const raw);

private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;
};

#endif
