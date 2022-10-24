/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:21:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 21:58:08 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : Form("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other ) : Form(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=( RobotomyRequestForm& other ) {
    ( void )other;
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    int  i = std::rand() % 100;
    
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw Form::GradeTooLowException();
    else {
        if ( i % 2 == 0 )
            std::cout << target << " has been robotomized!" << std::endl;
        else
            std::cout << "Robotomy failed! " << std::endl;
        i++;
    }
}
