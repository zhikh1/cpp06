/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:32:11 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/29 18:47:50 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cstdlib>

#define CNT (5)

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*   generate( void ) {
	int seed = std::rand() % 3;
	switch (seed)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (0);
	}
}

void    identify( Base* p ) {
    if ( dynamic_cast< A* >( p ) )
        std::cout << "A" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "B" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void    identify( Base& p ) {
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
    } catch( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
    } catch( const std::exception& e ) {}
}

int     main( void )
{
	Base*   randObject[CNT];
	int i = 0;

	try {
		for (i = 0; i < CNT; i++)
			randObject[i] = generate();
	}
    catch(const std::exception& e) 
    {
    	std::cout << e.what() << std::endl;
    	for ( ; i >= 0; i--)
    		delete randObject[i];
    	return 1;
    }

    
	for (i = 0 ; i < CNT; i++)
	{
		std::cout << "(Base*)   randObject[" << i << "] = "; identify( randObject[i] );
    	std::cout << "(Base&)  *randObject[" << i << "] = "; identify( *(randObject[i]) );
    	std::cout << std::endl;
   	}
    
    for (i = 0; i < CNT; i++)
    		delete randObject[i];

    return (0);
}
