/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:29:42 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 21:58:03 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : name(name), grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : name(src.name), grade(src.grade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
    grade = other.getGrade();
    return (*this);
}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void    Bureaucrat::incrementGrade() {
    if ( grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

void    Bureaucrat::signForm( Form& form ) {
    try {
        form.beSigned( *this );
        std::cout << *this << " signed " << form.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm( const Form& form ) const {
    try {
        form.execute( *this );
    } catch ( std::exception& e ) {
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& other ) {
    o << other.getName() << ", bureaucrat grade " << other.getGrade();
    return o;
}