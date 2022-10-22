/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:36:16 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/19 22:13:07 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.h"
#include "Form.h"

int main( void )
{
    Bureaucrat bureaucrat("Manager",8);
    Form form("check", 7);

    bureaucrat.signForm(form);
    std::cout << "<----------------------------------------->" << std::endl;
    bureaucrat.incrementGrade();
    bureaucrat.signForm(form);

    std::cout << form << std::endl;
    return (0);
}