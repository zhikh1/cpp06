/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:29:42 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/19 22:13:16 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : name(name), grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.name), grade(other.grade) {
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

std::ostream& operator<<( std::ostream& o, const Bureaucrat& other ) {
    o << other.getName() << ", bureaucrat grade " << other.getGrade();
    return o;
}