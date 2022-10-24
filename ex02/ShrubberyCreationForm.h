/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:34:26 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 22:02:47 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.h"
#include <fstream>
#include <cstring>

class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm( const std::string& target );
    ShrubberyCreationForm( const ShrubberyCreationForm& other );
    ~ShrubberyCreationForm();

    ShrubberyCreationForm&  operator=( ShrubberyCreationForm& other );

    void        execute( const Bureaucrat& executor ) const;

private:
    ShrubberyCreationForm();
    const std::string   target;

};

#endif
