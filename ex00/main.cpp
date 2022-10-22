/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:36:16 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/19 22:13:18 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.h"

int main( void )
{
    try {
        Bureaucrat bureaucrat("Tom", 3);

        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();

        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();

        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        // bureaucrat.decrementGrade();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}