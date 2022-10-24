/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:08:07 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 22:28:44 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.h"

Intern::Intern() {}

Intern::Intern( const Intern& other ) {
    *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=( const Intern& other ) {
    ( void ) other;
    return (*this);
}

Form*   Intern::makeForm( std::string name, std::string target ) {
    Form    *resultForm = 0;
    Form*    forms[] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
    };
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    
    for ( int i = 0; i < 3; i++ ) {
        if ( name == formNames[i] ) {
            std::cout << "Intern creates " << name << std::endl;
            resultForm = forms[i];
        }
        else
            delete forms[i];
    }
    if (resultForm == 0)
        std::cout << "Intern cannot create " << name << " form" << std::endl;
    return (resultForm);
}
