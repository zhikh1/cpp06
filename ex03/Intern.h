/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:05:37 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 22:13:12 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_H
#define INTERN_H

#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "Form.h"

class Intern {

public:
    Intern();
    Intern( const Intern& other );
    ~Intern();

    Intern& operator=( const Intern& other );

    Form*   makeForm( std::string name, std::string target );
};

#endif
