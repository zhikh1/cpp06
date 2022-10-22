/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:31:08 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/19 22:13:07 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
private:
    const std::string   name;
    bool                isSigned;
    const int           gradeToSign;
    const int           gradeToExecute;

    Form();

public:
    Form( const std::string& name, int gradeToSign );
    Form( const std::string& name, int gradeToSign, int gradeToExecute );
    Form( const Form& other );
    ~Form();

    Form&   operator=( const Form& other );

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned( const Bureaucrat& bureaucrat );


    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
};

std::ostream&   operator<<( std::ostream& o, const Form& other );

#endif