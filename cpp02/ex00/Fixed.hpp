#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
	int value;
	static const int bits = 8;

	public:
	
	// constructor
	Fixed( void );
	
	//Constructor with parameters
	Fixed(int value);

	// copy constructor
	Fixed(Fixed const &other);
	
	// copy assign operator
	Fixed& operator=(const Fixed& other);
	
	// destructor
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	static void teste(void);
};

#endif