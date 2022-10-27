/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:36:16 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/25 21:01:55 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

#include <iostream>
#include <cstdlib>

Base* generate() {
	std::srand(time(NULL));

	int n = rand() % 3;
	switch (n) {
		case 0:
			std::cout << "generated an A class" << std::endl;
			return new A;
		case 1:
			std::cout << "generated an B class" << std::endl;
			return new B;
		case 2:
			std::cout << "generated an C class" << std::endl;
			return new C;
	}

	std::cout << "some very weird error ocurred: can't generate a class" << std::endl;
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A class was identified" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B class was identified" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C class was identified" << std::endl;
	} else {
		std::cout << "Can't identify the class" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& aux = dynamic_cast<A&>(p); (void)aux;
		std::cout << "A class was identified" << std::endl;
		return;
	} catch (...) {}

	try {
		B& aux = dynamic_cast<B&>(p); (void)aux;
		std::cout << "B class was identified" << std::endl;
		return;
	} catch (...) {}

	try {
		C& aux = dynamic_cast<C&>(p); (void)aux;
		std::cout << "C class was identified" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Can't identify the class" << std::endl;
}

int main() {
	Base *base;

	base = generate();
	identify(base); // pointer
	identify(*base); // reference

	return 0;
}