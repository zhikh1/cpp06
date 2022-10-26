/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:36:16 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/25 21:01:55 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "CastPrinter.h"
#include <iostream>

int main( int argc, char *argv[] )
{
    CastPrinter print;
    if (argc == 2)
    {
        std::cout << "int: ";
        print.toInt(argv[1]);
        
        std::cout << "float: ";
        print.toFloat(argv[1]);
        
        std::cout << "double: ";
        print.toDouble(argv[1]);
        
        std::cout << "char: ";
        print.toChar(argv[1]);
    }
    else
        std::cout << "Bad args!" << std::endl;
    return (0);
}