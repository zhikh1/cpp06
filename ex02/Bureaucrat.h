/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:29:35 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/19 22:13:10 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "Form.h"

class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat( const std::string& name, int grade );
    Bureaucrat( const Bureaucrat& src );
    ~Bureaucrat();
    Bureaucrat& operator=( const Bureaucrat& other );

    std::string getName() const;
    int         getGrade() const;

    void        incrementGrade();
    void        decrementGrade();

    void        signForm( Form& form );

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
    
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };

private:
    const std::string   name;
    int                 grade;

};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& other );

#endif
