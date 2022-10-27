
#ifndef A_H
# define A_H

# include <iostream>
# include "Base.h"

class A: public Base
{

public:

	A( void );
	A( const A &src );
	~A( void );

	A	&operator=( const A &rhs );

private:

};

std::ostream	&operator<<( std::ostream &ostr, const A &instance );

#endif
