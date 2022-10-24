/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:31:08 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 21:58:05 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
public:
    Form( const std::string& name, int gradeToSign, int gradeToExecute );
    Form( const Form& other );
    virtual ~Form();

    Form&   operator=( const Form& other );

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned( const Bureaucrat& bureaucrat );

    virtual void        execute( const Bureaucrat& executor ) const = 0;

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
    class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form not signed"; }
    };

private:
    const std::string   name;
    bool                isSigned;
    const int           gradeToSign;
    const int           gradeToExecute;

    Form();
};

std::ostream&   operator<<( std::ostream& o, const Form& other );

#endif