/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastPrinter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:05:26 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/25 23:00:49 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "CastPrinter.h"

CastPrinter::CastPrinter(){}

CastPrinter::CastPrinter( const CastPrinter&){}

CastPrinter::~CastPrinter(){}

CastPrinter& CastPrinter::operator=( const CastPrinter& other ){
	if (this == &other)
		return (*this);
	return (*this);
}

int	CastPrinter::toInt(const std::string &str){
	int ret;
	if ( !isCorrectNum(str) )
		std::cout << "impossible" << std::endl;
	else
	{
		std::istringstream ss(str);	    
	    ss >> ret;
	    std::cout << ret << std::endl;
	}
	return(ret);
}

float	CastPrinter::toFloat(const std::string &str){
    float ret;
    if ( !std::isdigit(str[0]) && (str[0] == '-' && !std::isdigit(str[1])) )
		std::cout << "impossible" << std::endl;
	else
	{
		std::istringstream ss(str);	    
	    ss >> ret;
	    std::cout << ret << "f" << std::endl;
	}
	return(ret);
}

double	CastPrinter::toDouble(const std::string &str){
    double ret;
    if ( !std::isdigit(str[0]) && (str[0] == '-' && !std::isdigit(str[1])) )
		std::cout << "impossible" << std::endl;
	else
	{
		std::istringstream ss(str);	    
	    ss >> ret;
	    std::cout << ret << std::endl;
	}
	return(ret);
}

char	CastPrinter::toChar(const std::string &str){
    char ret;
    if ( !std::isdigit(str[0]) && (str[0] == '-' && !std::isdigit(str[1])) )
		std::cout << "impossible" << std::endl;
	else
	{
		std::istringstream ss(str);	    
	    ss >> ret;
	    std::cout << ret << std::endl;
	}
	return(ret);
}

NumType CastPrinter::isCorrectNum(const std::string &str)
{
	long unsigned int i = 0;
	int pointFlag = 0;
	long unsigned int signFlag = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		signFlag = 1;
		i++;
	}
	while (i < str.length())
	{
		std::cout << i  <<"|"  << str[i] << "|" << std::endl;
		if ( 
				!( ( std::isdigit(str[i]) || (!std::isdigit(str[i]) && str[i] == 'f' && i == (str.length() - 1) && i != signFlag) )  ) ||
				(  (str[i] == '.' && i != signFlag) || (str[i] == '.' && i != signFlag + 1 && signFlag == 1) || (str[i] == '.' && pointFlag != 1)   )
		   )
		{
			std::cout << "|"  <<  std::isdigit(str[i]) << !std::isdigit(str[i]) << (str[i] == 'f') << (i == (str.length() - 1)) << (i != signFlag) << "|" << std::endl;
			return (ERR);
		}
		if (str[i] == '.')
			pointFlag = 1;
		if (str[i] == 'f')
		{
			if (pointFlag)
				return (FLOAT);
			else
				return (ERR);
		}		
		i++;
	}
	if (signFlag == i)
		return (ERR);
	if (pointFlag == 1)
		return (DOUBLE);
	else
		return (INT);
}

NumType		CastPrinter::isNanInf(const std::string &str)
{
	if (	str.compare( "-inf" ) == 0 ||
			str.compare( "+inf " ) == 0 ||
			str.compare( "nan" ) == 0 )
		return (DOUBLE);
	else if ( str.compare( "-inff" ) == 0 ||
			  str.compare( "+inff" ) == 0 )
		return (FLOAT);
	else
		return (ERR);
}
