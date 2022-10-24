/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:30:58 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 21:58:05 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.h"

Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if ( gradeToSign < 1 || gradeToExecute < 1 )
        throw Form::GradeTooHighException();
    if ( gradeToSign > 150 || gradeToExecute > 150 )
        throw Form::GradeTooLowException();
}

Form::Form( const Form& other ): name( other.getName() ), gradeToSign( other.getGradeToSign() ), gradeToExecute( other.getGradeToExecute() ) {}

Form::~Form() {}

Form&   Form::operator=( const Form& other ) {
    isSigned = other.getSigned();
    return *this;
}

std::string Form::getName() const {
    return name;
}

bool   Form::getSigned() const {
    return isSigned;
}

int   Form::getGradeToSign() const {
    return gradeToSign;
}

int   Form::getGradeToExecute() const {
    return gradeToExecute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > gradeToSign )
        throw Form::GradeTooLowException();
    isSigned = true;
}

std::ostream&   operator<<( std::ostream& o, const Form& other ) {
    o << "Form \"" << other.getName() << "\" with grade to sign: " << other.getGradeToSign() << " and grade to execute: " << other.getGradeToExecute();
    return o;
}
