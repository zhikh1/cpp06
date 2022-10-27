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

int	CastPrinter::toInt(std::string str, bool print_en){
	int ret = 0;

	NumType numType =  getNumType(str);

	if ( numType == ERR )
	{
		if (print_en)
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::istringstream ss(str);	    
	    ss >> ret;
	    if (print_en)
			std::cout << ret << std::endl;
	}
	return(ret);
}

float	CastPrinter::toFloat(std::string str){
    float ret = 0.0f;

	NumType numType =  getNumType(str);
	NumType nanInfType = getNanInfType(str);

	if ( numType == ERR && nanInfType == ERR)
		std::cout << "impossible" << std::endl;
	else if (nanInfType == ERR)
	{
		if (numType == FLOAT)
			str.erase(str.length()-1,1);
		std::istringstream ss(str);
		ss >> ret;
		std::cout << ret;
		if (ret - toInt(str, false) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else if (nanInfType != FLOAT)
	{
		std::cout << str << "f" << std::endl;
	}		
	else
		std::cout << str << std::endl;
	return(ret);
}

double	CastPrinter::toDouble(std::string str){
    double ret = 0.0;

	NumType numType =  getNumType(str);
	NumType nanInfType = getNanInfType(str);

	if ( numType == ERR && nanInfType == ERR)
		std::cout << "impossible" << std::endl;
	else if (nanInfType == ERR)
	{
		if (numType == FLOAT)
			str.erase(str.length()-1,1);
		std::istringstream ss(str);		
		ss >> ret;
		std::cout << ret;
		if (ret - toInt(str, false) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (nanInfType != DOUBLE)
	{
		str.erase(str.length()-1,1);
		std::cout << str << std::endl;
	}
	else
		std::cout << str << std::endl;
	return(ret);
}

char	CastPrinter::toChar(std::string str){
    int tmp = toInt(str, false);
	char ret = static_cast<char>(tmp);
	NumType numType =  getNumType(str);

	if (tmp >= 0 && tmp < 256 && numType != ERR)
	{
		if (std::isprint(ret))
			std::cout << "\"" << ret << "\"" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
    
	
	return(ret);
}

NumType CastPrinter::getNumType(const std::string &str)
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
		if 	(
			   !( 	(  std::isdigit(str[i]) ) ||
					( !std::isdigit(str[i]) && str[i] == 'f' && i == (str.length() - 1) && i != signFlag && std::isdigit(str[i-1]) && pointFlag && i == (str.length() - 1))  ||
			   		( !std::isdigit(str[i]) && str[i] == '.' && i != signFlag && pointFlag == 0 && i != (str.length() - 1))  ) 
			)
			return (ERR);
		if (str[i] == '.')
			pointFlag = 1;
		i++;
	}
	if (signFlag == i)
		return (ERR);
	else if (str[i - 1] == 'f')
		return (FLOAT);
	else if (pointFlag == 1)
		return (DOUBLE);
	else
		return (INT);
	
}

NumType		CastPrinter::getNanInfType(const std::string &str)
{
	if (	str.compare( "-inf" ) == 0 ||
			str.compare( "+inf" ) == 0 ||
			str.compare( "nan" ) == 0 )
		return (DOUBLE);
	else if ( str.compare( "-inff" ) == 0 ||
			  str.compare( "+inff" ) == 0 ||
			  str.compare( "nanf" ) == 0 )
		return (FLOAT);
	else
		return (ERR);
}
