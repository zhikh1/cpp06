/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:18:44 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 21:58:07 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form( "PresidentialPardonForm", 25, 5 ), target( target ) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form( other ), target( other.target ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    (void)other;
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw Form::GradeTooLowException();
    else {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}
