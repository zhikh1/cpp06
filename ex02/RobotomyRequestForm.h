/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:28:23 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 21:58:08 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Form.h"
#include <stdlib.h>

class RobotomyRequestForm : public Form
{
private:
    const std::string   target;

    RobotomyRequestForm();

public:
    RobotomyRequestForm( const std::string& target );
    RobotomyRequestForm( const RobotomyRequestForm& other );
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=( RobotomyRequestForm& other );

    void        execute( const Bureaucrat& executor ) const;
};

#endif
